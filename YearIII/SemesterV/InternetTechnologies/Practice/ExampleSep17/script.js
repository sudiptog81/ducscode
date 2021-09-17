const submitBtn = document.getElementById('submit');
const container = document.getElementById('container');
const orderSelect = document.getElementById('order');
const saveBtn = document.getElementById('actions').firstChild.nextSibling;
const resetBtn = document.getElementById('actions').lastChild.previousSibling;

let list;

submitBtn.addEventListener('click', () => {
  try {
    container.innerHTML = '';

    const string = submitBtn.parentNode.firstChild.nextSibling.value
      .trim()
      .replaceAll(' ', '');

    list = string
      .split(',')
      .map((e) => {
        if (isNaN(e)) throw new Error('Invalid Input');
        return +e;
      });

    const order = orderSelect.options[orderSelect.selectedIndex].getAttribute('value');

    bubbleSort([...list], order === 'asc');

    saveBtn.disabled = false;
    resetBtn.disabled = false;
  } catch (e) {
    alert(e);
  }
});

const bubbleSort = (list, order) => {
  for (let i = 0; i < list.length; i++) {
    displayList(list, i);
    for (let j = 0; j < list.length - i - 1; j++) {
      if (order && list[j] > list[j + 1]) {
        const temp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = temp;
      } else if (!order && list[j] < list[j + 1]) {
        const temp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = temp;
      }
    }
  }
  return list;
};

const displayList = (list, idx) => {
  const row = document.createElement('div');
  row.className = 'row';
  list.forEach((e, i) => {
    const span = document.createElement('span');
    span.className = 'element';
    span.innerText = e;
    row.appendChild(span);
    if (i === idx) {
      span.setAttribute('data-current', 1);
    }
  });
  container.appendChild(row);
};

resetBtn.addEventListener('click', () => {
  Array.from(container.childNodes).map((e) => e.remove());
  saveBtn.disabled = true;
  resetBtn.disabled = true;
});

saveBtn.addEventListener('click', () => {
  try {
    const spanElements = document.getElementsByTagName('span');
    const numbers = Array.from(spanElements).slice(spanElements.length - list.length).map((e) => e.innerText);
    const text = `List: ${list.join(', ')}\nSorted List: ${numbers.join(', ')}`;
    const file = new Blob([...text], { type: 'text/plain' });
    const a = document.createElement("a"),
      url = URL.createObjectURL(file);
    a.href = url;
    a.download = 'results.txt';
    document.body.appendChild(a);
    a.click();
    setTimeout(() => {
      document.body.removeChild(a);
      window.URL.revokeObjectURL(url);
    }, 0);
  } catch (e) {
    alert(e);
  }
});
