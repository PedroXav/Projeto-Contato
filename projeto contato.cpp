#include <iostream>
#include <string>
using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int dia, int mes, int ano) {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }

    Data() {
        this->dia = 0;
        this->mes = 0;
        this->ano = 0;
    }

    void setDia(int dia) {
        this->dia = dia;
    }

    void setMes(int mes) {
        this->mes = mes;
    }

    void setAno(int ano) {
        this->ano = ano;
    }

    int getDia() {
        return this->dia;
    }

    int getMes() {
        return this->mes;
    }

    int getAno() {
        return this->ano;
    }

    string getData() {
        string sDia = to_string(this->dia);
        string sMes = to_string(this->mes);
        string sAno = to_string(this->ano);

        return sDia.insert(0, 2 - sDia.size(), '0') + "/" +
               sMes.insert(0, 2 - sMes.size(), '0') + "/" +
               sAno;
    }

    Data* dia_seguinte() {
        Data* d1 = new Data(this->dia, this->mes, this->ano);
        int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (d1->ano % 4 == 0) {
            diasNoMes[1] = 29;
        }
        d1->dia++;
        if (d1->dia > diasNoMes[d1->mes - 1]) {
            d1->dia = 1;
            d1->mes++;
            if (d1->mes > 12) {
                d1->mes = 1;
                d1->ano++;
            }
        }
        return d1;
    }

}; 

class Contato {
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:
    Contato() {}

    void setEmail(string email) {
        this->email = email;
    }

    void setNome(string nome) {
        this->nome = nome;
    }

    void setTelefone(string telefone) {
        this->telefone = telefone;
    }

    void setDtnasc(Data dtnasc) {
        this->dtnasc = dtnasc;
    }

    string getEmail() {
        return this->email;
    }

    string getNome() {
        return this->nome;
    }

    string getTelefone() {
        return this->telefone;
    }

    Data getDtnasc() {
        return this->dtnasc;
    }

    int idade() {
        Data hoje(1, 1, 2024); 
        int idade = hoje.getAno() - this->dtnasc.getAno();
        if (hoje.getMes() < this->dtnasc.getMes() ||
            (hoje.getMes() == this->dtnasc.getMes() && hoje.getDia() < this->dtnasc.getDia())) {
            idade--;
        }
        return idade;
    }
}; 

int main() {
    Contato contatos[5];
    Data dataNascimento;

    for (int i = 0; i < 5; i++) {
        cout << "Digite o nome do contato " << i + 1 << ": ";
        string nome;
        getline(cin >> ws, nome); 
        contatos[i].setNome(nome);

        cout << "Digite o e-mail do contato " << i + 1 << ": ";
        string email;
        getline(cin >> ws, email);
        contatos[i].setEmail(email);

        cout << "Digite o telefone do contato " << i + 1 << ": ";
        string telefone;
        getline(cin >> ws, telefone);
        contatos[i].setTelefone(telefone);

        cout << "Digite a data de nascimento (um de cada vez, dia mes ano) do contato " << i + 1 << ": ";
        int dia, mes, ano;
        cin >> dia >> mes >> ano;
        dataNascimento.setDia(dia);
        dataNascimento.setMes(mes);
        dataNascimento.setAno(ano);
        contatos[i].setDtnasc(dataNascimento);

        cout << endl;
    }

    
    cout << "Contatos cadastrados:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Contato " << i + 1 << ":" << endl;
        cout << "Nome: " << contatos[i].getNome() << endl;
        cout << "E-mail: " << contatos[i].getEmail() << endl;
        cout << "Telefone: " << contatos[i].getTelefone() << endl;
        cout << "Data de nascimento: " << contatos[i].getDtnasc().getData() << endl;
        cout << "Idade: " << contatos[i].idade() << " anos" << endl << endl;
    }

    return 0;
}

