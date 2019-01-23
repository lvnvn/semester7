#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sys/stat.h>

class Rotor
{
public:
    Rotor(){}
    ~Rotor(){}
    void Generate();
    int Translate(int letter);
    int TranslateBack(int letter);
    void Turn();
    int pos[256];
};

void Rotor::Generate()
{
    for(int i=0; i<256; i++)
    {
        pos[i] = i;
    }

    for(int i=0; i<256; i++)
    {
        int exchange = rand()%256;
        int tmp = pos[i];
        pos[i] = pos[exchange];
        pos[exchange] = tmp;
    }
}

int Rotor::Translate(int letter)
{
    return pos[letter];
}

int Rotor::TranslateBack(int letter)
{
    return std::distance(pos, std::find(pos, pos + 256, letter)); //index of letter in pos
}

void Rotor::Turn()
{
    int tmp = pos[255];
    for(int i=255; i>0; i--)
    {
        pos[i] = pos[i-1];
    }
    pos[0] = tmp;
}


class Reflector
{
public:
    Reflector(){}
    ~Reflector(){}
    void Generate();
    int Translate(int letter);
    int pos[256];
};

void Reflector::Generate()
{
    for(int i=0; i<256; i++)
    {
        pos[i] = i;
    }

    for(int i=0; i<256; i++)
    {
        if(pos[i] == i)
        {
            int exchange = rand()%256;
            while((pos[exchange] != exchange) || (exchange == i))
                exchange = rand()%256;
            pos[i] = pos[exchange];
            pos[exchange] = i;
        }
    }
}

int Reflector::Translate(int letter)
{
    return pos[letter];
}

class Machine
{
public:
    Machine(){}
    ~Machine(){}
    void Init();
    int* Encode(int* input, int N);
    int* Decode(int* input, int N, Rotor* rotors);
    Rotor* GetRotors();
    Rotor rotors[3];
    Reflector reflector;
};

void Machine::Init()
{
    rotors[0].Generate();
    rotors[1].Generate();
    rotors[2].Generate();
    reflector.Generate();
}

Rotor* Machine::GetRotors()
{
    return rotors;
}

int* Machine::Encode(int* input, int N)
{
    int turncount[] = {0, 0, 0};
    int *res_arr = new int[N];
    for(int i = 0; i < N; i++)
    {
        int symbol = input[i];
        //std::cout << "\n" << symbol;
        for(int j = 0; j < 3; j++)
        {
            symbol = rotors[j].Translate(symbol);
            //std::cout << " rot " << symbol;
        }
        symbol = reflector.Translate(symbol);
        //std::cout << " refl " << symbol;
        for(int j = 2; j >= 0; j--)
        {
            symbol = rotors[j].TranslateBack(symbol);
            //std::cout << " rot back " << symbol;
        }
        res_arr[i] = symbol;
        rotors[0].Turn();
        turncount[0]++;
        if(turncount[0] == 256)
        {
            rotors[2].Turn();
            turncount[0] = 0;
            turncount[1]++;
        }
        if(turncount[1] == 256)
        {
            rotors[3].Turn();
            turncount[1] = 0;
            turncount[2]++;
        }
    }
    return res_arr;
}

int* Machine::Decode(int* input, int N, Rotor* saved_rotors)
{
    for(int i=0; i<3; i++)
        for(int j = 0; j < 256; j++)
            rotors[i].pos[j] = saved_rotors[i].pos[j];

    return Encode(input, N);
}

int main()
{
    char* path = "/home/daria/labs_sem7/zi/enigma/archive.tar.gz";
    char* decoded_filename = "../enigma/decoded.tar.gz";
    srand(time(NULL));
    Machine machine;
    machine.Init();

    Rotor rotor_state[3];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 256; j++)
            rotor_state[i].pos[j] = machine.GetRotors()[i].pos[j];

    struct stat results;
    stat(path, &results);
    long size = results.st_size;
    char* file_contents = new char[size]();
    std::ifstream file (path, std::ios::in | std::ios::binary);
    file.read(file_contents, size);

    int *in_arr = new int[size];
    for(int i = 0; i < size; i++)
        in_arr[i] = file_contents[i]+128;

    int* encoded = machine.Encode(in_arr,size);
    char* encoded_char = new char[size]();;
    for(int i = 0; i < size; i++)
        encoded_char[i] = encoded[i]-128;
    std::ofstream encoded_file ("../enigma/encoded.txt", std::ios::out | std::ios::binary);
        encoded_file.write (encoded_char, size);

    int* decoded = machine.Decode(encoded, size, rotor_state);
    char* decoded_char = new char[size]();;
    for(int i = 0; i < size; i++)
        decoded_char[i] = decoded[i]-128;
    std::ofstream decoded_file (decoded_filename, std::ios::out | std::ios::binary);
        decoded_file.write (decoded_char, size);

}
