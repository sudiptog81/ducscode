const mainEl = document.getElementById('main');

var i = 2;
var j = 1;
var t = 1;

var colors = ['#E74C3C', '#3498DB', '#27AE60', '#8E44AD', '#000000'];

setInterval(() => {
  if (j > 10) {
    i++;
    j = 1;
  }

  if (i > 10) return;

  const child = document.createElement('p');
  child.innerHTML = `${i} * ${j} = ${i * j}`;
  child.style.color = colors[(j - 1) % 5];
  child.style.fontSize = `${t}rem`;
  mainEl.appendChild(child);
  window.scrollTo(0, document.body.scrollHeight);

  j++;
  t += 0.05;
}, 5e3);
