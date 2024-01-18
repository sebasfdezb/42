var colors = ['pink', 'blue', 'green', 'yellow'];
var currentColor = 0;

function changeColor(){
	document.body.style.background= colors[currentColor];
	currentColor = (currentColor + 1) % colors.length;
}

function myFunc(){
	changeColor(currentColor);
}