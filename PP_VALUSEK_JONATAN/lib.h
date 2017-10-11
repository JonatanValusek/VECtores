#define MAX_QTY 200

typedef struct{
    char nombre[25];
    char apellido[25];
    long int dni;
    int clienteId;
    int status; /**< Active (1) or Inactive (0) or 2 LOW  */
}cliente;

typedef struct{
    char name[51];
    char lastName[51];
    int authorId;
    int status; /**< Active (1) or Inactive (0) or (2) LOW */
}author;

void setClienteStatus(cliente clienteArray[],int arrayLenght,int value);
int findClienteEmptyPlace(cliente clienteArray[],int arrayLenght);
int findClienteByCode(cliente clienteArray[],int arrayLenght,int code);
void setCliente(cliente clienteArray[],int freePlaceIndex, int codeAux,char nombreAux[],char apellidoAux[],long int dniAux);
void showClienteArray(cliente clienteArray[],int arrayLenght);
/*void orderClienteArrayByTitle(cliente clienteArray[],int arrayLenght);*/

/*void setAuthorStatus(author authorArray[],int arrayLenght,int value);
int findAuthorEmptyPlace(author authorArray[],int arrayLenght);
int findAuthorById(author authorArray[],int arrayLenght,int authorIdAux);
void setAuthor(author authorArray[],int freePlaceIndex, int authorIdAux,char nameAux[],char lastNameAux[]);
void showAuthorArray(author authorArray[],int arrayLenght);

void showBookAuthorArray(book bookArray[],int arrayLenght,author authorArray[],int authorArrayLenght);
*/
