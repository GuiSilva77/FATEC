const container = document.getElementById("container");

class no {
  constructor(value) {
    this.value = value;
    this.prox = null;
  }
}
debugger;
class LinkedList {
  adicionar_fim(value) {
    if (inicio == null) inicio = new no(value);

    let aux = inicio;
    while (aux.prox != null) {
      aux = aux.prox;
    }
    aux.prox = new no(value);
  }

  listar_nos(inicio) {
    let aux = inicio;
    while (aux != null) {
      container.innerText += " " + aux.value + " ";
      aux = aux.prox;
    }
  }
}

let inicio = new LinkedList();

let flag = 9;
while (flag) {
  inicio.adicionar_fim(flag);
  flag--;
}

inicio.listar_nos(inicio);
