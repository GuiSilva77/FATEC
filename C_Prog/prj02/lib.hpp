/**
 * @file lib.hpp
 * @author Guilherme Silva (guilherme92325@gmail.com)
 * @brief  biblioteca de funcoes e clases para o projeto
 * @version 0.1
 * @date 2022-02-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef LIB_HPP
#define LIB_HPP
#endif

#include <iostream>
#include <string>

/**
 * @brief Namespace para funçõpes e classes sobre operações bancárias
 *
 * @namespace opb
 *
 */
namespace opb
{
  /**
   * @brief Classe para representar uma conta bancária
   **/
  class Conta
  {
  private:
    int cpf;
    float saldo_conta_poupanca;
    float saldo_conta_corrente;
    int senha;
    Conta *prox;

    public:
    std::string nome;
    int conta_corrente;
    

    /**
     * @brief Construtor da classe Conta
     * @param nome Nome do cliente
     * @param cpf CPF do cliente
     * @param saldo_conta_poupanca Saldo da conta poupança
     * @param saldo_conta_corrente Saldo da conta corrente
     * @param senha Senha da conta
     * @param conta_corrente Número da conta corrente
     * @return Conta
     * @see Conta
     * */
    Conta(std::string nome, int cpf, float saldo_conta_poupanca, float saldo_conta_corrente, int senha, int conta_corrente)
    {
      this->nome = nome;
      this->cpf = cpf;
      this->saldo_conta_poupanca = saldo_conta_poupanca;
      this->saldo_conta_corrente = saldo_conta_corrente;
      this->senha = senha;
      this->conta_corrente = conta_corrente;
    };

    std::string getNome()
    {
      return this->nome;
    }

    void setNome(std::string nome)
    {
      this->nome = nome;
    }

    int getCpf()
    {
      return this->cpf;
    }

    void setCpf(int cpf)
    {
      this->cpf = cpf;
    }

    float getSaldo_conta_poupanca()
    {
      return this->saldo_conta_poupanca;
    }

    void setSaldo_conta_poupanca(float saldo_conta_poupanca)
    {
      this->saldo_conta_poupanca = saldo_conta_poupanca;
    }

    float getSaldo_conta_corrente()
    {
      return this->saldo_conta_corrente;
    }

    void setSaldo_conta_corrente(float saldo_conta_corrente)
    {
      this->saldo_conta_corrente = saldo_conta_corrente;
    }

    int getSenha()
    {
      return this->senha;
    }

    void setSenha(int senha)
    {
      this->senha = senha;
    }

    Conta* getProx()
    {
      return this->prox;
    }

    void setProx(Conta *prox)
    {
      this->prox = prox;
    }
  };

  class Lista_contas
  {
    private:
      Conta *contas = NULL;
      int tamanho = 0;
      
    public:
      void adicionar_conta(Conta conta)
      {
        if (this->contas == NULL)
        {
          this->contas = new Conta(conta);
          this->tamanho++;
        }
        else
        {
          Conta *aux = this->contas;
          while (aux->getProx() != NULL)
          {
            aux = aux->getProx();
          }
          aux->setProx(new Conta(conta));
          this->tamanho++;
        }
      }

      void remover_conta(int cpf)
      {
        if (this->contas == NULL)
        {
          std::cout << "Não há contas cadastradas" << std::endl;
        }
        else
        {
          Conta *aux = this->contas;
          while (aux->getProx() != NULL)
          {
            if (aux->getProx()->getCpf() == cpf)
            {
              Conta *aux2 = aux->getProx();
              aux->setProx(aux2->getProx());
              delete aux2;
              this->tamanho--;
              break;
            }
            aux = aux->getProx();
          }
        }
      }
  };

};
