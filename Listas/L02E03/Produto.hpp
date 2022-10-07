#ifndef PRODUTO_H
#define PRODUTO_H

class Produto {
    private:
        int _id;
        float _valor_unitario;
    
    public:
        Produto(int id=0, float valor_unitario=0);
        int getId();
        float getValorUnitario();
        void setId(int id);
        void setValorUnitario(float valor_unitario);
        virtual void imprimir_info() = 0;
};

#endif