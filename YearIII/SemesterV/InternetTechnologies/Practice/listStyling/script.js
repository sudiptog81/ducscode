document.querySelectorAll('.action-delete').forEach(action => {
  action.addEventListener('click', () => {
    confirm('Are you sure?') && action.parentNode.parentNode.remove();
  });
});

document.querySelectorAll('.action-edit').forEach(action => {
  action.addEventListener('click', () => {
    action.parentNode.parentElement.children[1].innerText =
      prompt('Rename task: ',
        action.parentNode.parentElement.children[1].innerText)
      || action.parentNode.parentElement.children[1].innerText;
  });
});

document.querySelectorAll('.task-check').forEach(task => {
  task.addEventListener('change', () => {
    task.parentNode.parentNode.classList.toggle('done');
  });
});


document.getElementById('addTask').addEventListener('click', () => {
  const newTask = document.createElement('li');
  newTask.classList.add('task');

  const taskDiv1 = document.createElement('div');
  const taskCheckbox = document.createElement('input');
  taskCheckbox.setAttribute('type', 'checkbox');
  taskCheckbox.classList.add('task-check');
  taskCheckbox.addEventListener('change', () => newTask.classList.toggle('done'));
  taskDiv1.appendChild(taskCheckbox);
  newTask.appendChild(taskDiv1);

  const taskDiv2 = document.createElement('div');
  taskDiv2.appendChild(document.createTextNode(document.getElementById('newTask').value));
  newTask.appendChild(taskDiv2);

  const taskDiv3 = document.createElement('div');
  taskDiv3.classList.add('action');
  taskDiv3.innerHTML = `<i class="fa fa-pen action-edit"></i><i class="fa fa-trash action-delete"></i>`;
  taskDiv3.children[0].addEventListener('click', () => taskDiv2.innerText = prompt('Rename task: ', taskDiv2.innerText) || taskDiv2.innerText);
  taskDiv3.children[1].addEventListener('click', () => confirm('Are you sure?') && newTask.remove());
  newTask.appendChild(taskDiv3);


  document.getElementById('tasks').appendChild(newTask);
  document.getElementById('newTask').value = '';
});


