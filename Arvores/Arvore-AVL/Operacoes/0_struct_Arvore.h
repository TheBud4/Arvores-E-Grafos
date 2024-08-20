#ifndef STRUCT_ARVORE_H
#define STRUCT_ARVORE_H

struct nohArvore{
   void*              info;
   struct nohArvore  *esquerda;
   struct nohArvore  *direita;
   int    fb;
};

#endif
