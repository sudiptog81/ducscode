const form = document.getElementById('form');
form.addEventListener('submit', (e) => {
  e.preventDefault();
  const book = Object();
  book.name = document.getElementById('name').value;
  book.author = document.getElementById('author').value;
  book.price = document.getElementById('price').value;
  book.publisher = document.getElementById('publisher').value;
  book.category = document.getElementById('category').value;
  console.log('Object:', book);
  console.log('JSON:', JSON.stringify(book, null, 2));
  window.alert('Printed Book Object to the Console');
});
