exitCell(currentCell) {
  if(currentCell) is the Exit {
    success;
  }
  else {
    exitCell(The passage above currentCell);
    exitCell(The passage below currentCell);
    exitCell(The passage left of currentCell);
    exitCell(The passage right of currentCell);
  }
}
