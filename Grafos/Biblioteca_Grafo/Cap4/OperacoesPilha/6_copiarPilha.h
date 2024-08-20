pDPilha copiarPilha (pDPilha pd, FuncaoAlocacao pfa){
    pDPilha pDCopia = criarPilha();
    pDPilha pDAux = criarPilha();

    int count = 0;
    void *info;
    void *infoCopia;

    while(pilhaVazia(pd) == 0){
        empilharInfo(pDAux, desempilharInfo(pd));
        count++;
    }
    count = 0;
    while(pilhaVazia(pDAux) == 0){
        info = desempilharInfo(pDAux);
        infoCopia = pfa(info);
        empilharInfo(pd, info);
        empilharInfo(pDCopia, infoCopia);
        count++;
    }
    return pDCopia;
}