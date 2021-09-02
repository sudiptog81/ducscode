const paragraph = document.querySelector('p');

/**
 * set font color
 */
document.getElementById('c-red').addEventListener('click', () => {
  paragraph.style.color = '#f00';
});

document.getElementById('c-green').addEventListener('click', () => {
  paragraph.style.color = '#0f0';
});

document.getElementById('c-blue').addEventListener('click', () => {
  paragraph.style.color = '#00f';
});

/**
 * set font size
 */
document.getElementById('s-10').addEventListener('click', () => {
  paragraph.style.fontSize = '10px';
});

document.getElementById('s-20').addEventListener('click', () => {
  paragraph.style.fontSize = '20px';
});

document.getElementById('s-30').addEventListener('click', () => {
  paragraph.style.fontSize = '30px';
});

/**
 * set font family
 */
document.getElementById('f-mono').addEventListener('click', () => {
  paragraph.style.fontFamily = 'monospace';
});

document.getElementById('f-sans').addEventListener('click', () => {
  paragraph.style.fontFamily = 'sans-serif';
});

document.getElementById('f-serif').addEventListener('click', () => {
  paragraph.style.fontFamily = 'serif';
});

