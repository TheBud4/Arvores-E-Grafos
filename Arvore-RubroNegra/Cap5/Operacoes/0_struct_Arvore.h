#ifndef STRUCT_ARVORE_H
#define STRUCT_ARVORE_H

#define RED   'R'
#define BLACK 'B'

struct nohArvore{
   void*              info;
   struct nohArvore  *esquerda;
   struct nohArvore  *direita;

   char               cor;
   struct nohArvore  *pai;
};

#endif
