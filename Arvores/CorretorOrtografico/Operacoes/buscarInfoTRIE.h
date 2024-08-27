#ifndef BUSCARINFOTRIE_H_INCLUDED
#define BUSCARINFOTRIE_H_INCLUDED

bool buscarInfoTRIE(Noh *raiz, char *textoComSinal){

unsigned char *texto = (unsigned char*)textoComSinal;
int tamanho = strlen(textoComSinal);
Noh *temp = raiz ;

for(int i = 0; i < tamanho ; i++){

    if(temp->filhos[texto[i]] == NULL){
        return false;
    }
    temp = temp->filhos[texto[i]] ;
}

return temp->terminal;
}


#endif // BUSCARINFOTRIE_H_INCLUDED
