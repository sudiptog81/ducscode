let toastCounter = 0;

const debugInfoWindow = document.getElementById('debugInfoWindow');
const debugInfoDocument = document.getElementById('debugInfoDocument');

const update = () => {
  debugInfoWindow.innerHTML = dedent`
    Window Height: ${window.innerHeight}
    Window Width: ${window.innerWidth}
    Horizonal Scroll: ${window.pageXOffset}
    Vertical Scroll: ${window.pageYOffset}
    Pointer Coordinates: (${window.pageXOffset}, ${window.pageYOffset})
    Current URL: ${window.location}
    Number of Items in History: ${window.history.length}
    Screen Resolution: ${window.screen.width}x${window.screen.height}
  `;
};

document.getElementById('aboutBrowser').addEventListener('click', () => window.alert(dedent`
  Browser Platform: ${window.navigator.platform}
  Browser User Agent String: ${window.navigator.userAgent}
  Browser Language: ${window.navigator.language}
`));

document.getElementById('viewCode').addEventListener('click', () => window.open('https://github.com/sudiptog81/ducscode/tree/master/YearIII/SemesterV/InternetTechnologies/Practice/WindowDOMPractice/'));

document.getElementById('print').addEventListener('click', () => window.print());

(() => {
  update();
  setInterval(update, 5e2);
})();

debugInfoDocument.innerHTML = dedent`
    Document Title: ${document.title}
    Last Modified: ${document.lastModified}
    Domain: ${document.domain}
    Buttons on this page: ${document.querySelectorAll('button').length}
`;

document.getElementById('createToast').addEventListener('click', () => {
  toastCounter += 1;
  const toast = document.createElement('div');
  toast.classList.add('toast');
  toast.innerHTML = `This is toast #${toastCounter}!`;
  document.body.appendChild(toast);
  setTimeout(() => toast.remove(), 2e3);
});
