// main.cpp
#include <cstring>
#include <cstdlib>
#include <cmath>
#include "protocol.hpp"

void getch()
{
  cin.ignore();
  cin.get();
  return;
}

void clrscr()
{
#ifdef _WIN32
  system("cls");
#elif __unix__
  system("clear");
#endif
  return;
}

class selectiveRepeatSlidingWindow : public Protocol
{
public:
  string in_buf;

  selectiveRepeatSlidingWindow(int n, string s)
  {
    MAX_SEQ = n;
    in_buf = s;
  }

  void sender();
  void receiver();
};

void selectiveRepeatSlidingWindow::sender()
{
  event = frameArrival;
  printf("\n\nSENDER\n======");
  if (frameToSend ==
          (err + (MAX_SEQ / 2)) %
              (MAX_SEQ + 1) &&
      errorDetected == true &&
      err >= 0)
  {
    event = timeout;
    frameToSend = err;
    errorDetected = 0;
  }
  else if (frameToSend == MAX_SEQ &&
           frameToSend != frameExpected &&
           errorDetected == true)
  {
    fromNetworkLayer(dataPacket);
    frameToSend = frameExpected;
    errorDetected = false;
  }
  else if (event == frameArrival)
  {
    printf("\nEncapsulating Data '%c' into a Packet ...", in_buf[frameToSend]);
    dataPacket.data = in_buf[frameToSend];
    printf("\nPassing Packet to Data Link Layer ...");
    fromNetworkLayer(dataPacket);
  }
  toPhysicalLayer(senderFrame);
  receiver();
}

void selectiveRepeatSlidingWindow::receiver()
{
  printf("\n\nRECEIVER\n========");
  fromPhysicalLayer(senderFrame);
  toPhysicalLayer(receiverFrame);
  getch();
  clrscr();
  sender();
}

int main()
{
  int n;
  cout << "\nEnter bits needed to identify window: ";
  cin >> n;

  char temp[50];
  printf("Enter Data: ");
  scanf("%s", temp);

  selectiveRepeatSlidingWindow *obj =
      new selectiveRepeatSlidingWindow(
          pow(2, n) - 1,
          string(temp));
  obj->sender();
  delete obj;

  return 0;
}
