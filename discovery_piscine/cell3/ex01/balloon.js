let circle = document.querySelector('.circle');
let currentSize = circle.offsetWidth;
var colors = ['red', 'green'];
var currentColor = 0;

function increaseSize() {
   let newSize = currentSize + 10;
   if (newSize > 420){
	newSize = 200;
   }
   circle.style.width = `${newSize}px`;
   circle.style.height = `${newSize}px`;
   currentSize = newSize;
}

function changeColor(){
	circle.style.backgroundColor= colors[currentColor];
	currentColor = (currentColor + 1) % colors.length;
}

circle.addEventListener('click', increaseSize);
circle.addEventListener('click', changeColor);

circle.addEventListener('mouseover', function() {
	let newSize = Math.max(currentSize - 5, 200);
	circle.style.width = `${newSize}px`;
	circle.style.height = `${newSize}px`;
	currentSize = newSize;
	currentColor = (currentColor + 1) % colors.length;
	circle.style.backgroundColor = colors[currentColor];
 });
 
 // Evento para cuando el mouse sale del círculo
 circle.addEventListener('mouseout', function() {
	let newSize = currentSize + 5;
	circle.style.width = `${newSize}px`;
	circle.style.height = `${newSize}px`;
	currentSize = newSize;
	currentColor = (currentColor + 1) % colors.length;
	circle.style.backgroundColor = colors[currentColor];
 });
