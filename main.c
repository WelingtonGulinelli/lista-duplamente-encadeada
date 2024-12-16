#include <stdio.h>

struct listNode {
  char data;                // cada nó contém um character
  struct listNode *nextPtr; // ponteiro para o próximo nó
  struct listNode *backPtr;
};

typedef struct listNode ListNode; // tipo definido para struct listNode
typedef ListNode *ListNodePtr;    // Tipo definido para ListNode*

char value;
void insert(ListNodePtr *sPtr, char value);
void printList(ListNodePtr currentPtr);

int main(void) {
  ListNodePtr startPtr = NULL; // (Head) inicialização de uma lista Vazia
  char item;

 // printf("%s", "Enter a character: ");
// scanf("\n%c", &item);
  insert(&startPtr, '6');
  insert(&startPtr, '7');
  insert(&startPtr, '8'); // Inserir item na lista
  insert(&startPtr, '2');
  printList(startPtr);

  return 0;
}

void insert(ListNodePtr *sPtr, char value) {
  ListNodePtr newPtr = malloc(sizeof(ListNode)); // cria um nó
  if (newPtr != NULL) { // verifica se tem espaço disponível
    newPtr->backPtr = NULL;  // inicializa o ponteiro do nó para nulo
    newPtr->data = value;   // coloca o valor no atributo >> data <<
    newPtr->nextPtr = NULL; // inicializa o ponteiro do nó para nulo

    ListNodePtr currentPtr = *sPtr;

    // loop para encontrar a posição do caracter na lista
    while (currentPtr != NULL && value > currentPtr->data) {
      // caminha para ...
      currentPtr->backPtr = currentPtr;
      currentPtr = currentPtr->nextPtr; // ... o próximo nó
    }
    if (currentPtr != NULL && value == currentPtr->data) {
      printf("O valor já existe na lista\n");
      return;
    }

    // >> Inserção no início  <<
    if (currentPtr == NULL) {
      newPtr->nextPtr = *sPtr;
      *sPtr = newPtr;
    } else { // >> Inserção no meio <<
      newPtr->backPtr = currentPtr;
      newPtr->nextPtr = currentPtr->nextPtr;
      currentPtr->nextPtr->backPtr = newPtr;
      currentPtr->nextPtr = newPtr;
    }
  } else {
    printf("%c not inserted. No memory available.\n", value);
  }
}

void printList(ListNodePtr currentPtr) {
  // caso a lista esteja vazia
  if (currentPtr == NULL) {
    puts("List is empty.\n");
  } else {
    puts("The list is:");

    // enquanto não encontrar o fim da fila ...
    while (currentPtr != NULL) {
      printf("%c --> ", currentPtr->data);
      currentPtr = currentPtr->nextPtr;
    }
    puts("NULL\n");
  }
}
