document.querySelectorAll('.task').forEach(task => {
  task.addEventListener('click', () => task.classList.toggle('done'));
  task.addEventListener('dblclick', () => task.remove());
});

document.getElementById('addTask').addEventListener('click', () => {
  const newTask = document.createElement('li');
  const newTaskLabel = document.createElement('div');
  newTask.appendChild(newTaskLabel);
  newTask.classList.add('task');
  newTaskLabel.innerText = document.getElementById('newTask').value;
  newTask.addEventListener('click', () => newTask.classList.toggle('done'));
  newTask.addEventListener('dblclick', () => newTask.remove());
  document.getElementById('tasks').appendChild(newTask);
  document.getElementById('newTask').value = '';
});


