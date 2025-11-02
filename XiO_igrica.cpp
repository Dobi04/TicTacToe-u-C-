#include<iostream>
#include<ctime>

void uputstva();
void nacrtajTablu(char *razmaci);
void potezIgraca(char *razmaci, char igrac);
void potezIgraca2(char *razmaci, char igrac);
void potezKompijutera(char *razmaci, char kompijuter, char igrac);
bool proveriPobeduPVP(char *razmaci, char igrac, char kompijuter);
bool porveriPobedu(char *razmaci, char igrac, char kompijuter);
bool proveriNereseno(char *razmaci, bool kraj);

int main(){
    char razmaci[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char igrac = 'X';
    char kompijuter = 'O';
    bool igranje = true;
    bool kraj = false;
    int gamemode;

    std::cout << "\n\n**        Izaberite gamemode        **\n";
    std::cout << "#1: Igrac protiv igraca \n";
    std::cout << "#2: Igrac protiv kompijutera (Igrac igra prvi) \n";
    std::cout << "#3: Igrac protiv kompijutera (Kompijuter igra prvi)\n";
    std::cin >> gamemode;

    uputstva();
    
    nacrtajTablu(razmaci);

    while (igranje == true)
    {
        if (gamemode != 1)
        {
            break;
        }
        potezIgraca(razmaci, igrac);
        kraj = proveriPobeduPVP(razmaci, igrac, kompijuter);        
        igranje = proveriNereseno(razmaci, kraj);
        if (igranje == false)
        {
            break;
        }
        
        potezIgraca2(razmaci,kompijuter);
        kraj = proveriPobeduPVP(razmaci, igrac, kompijuter);
        igranje = proveriNereseno(razmaci, kraj);
    }

    while (igranje == true)
    {
        if (gamemode != 2)
        {
            break;
        }
        potezIgraca(razmaci, igrac);
        kraj = porveriPobedu(razmaci, igrac, kompijuter);        
        igranje = proveriNereseno(razmaci, kraj);
        if (igranje == false)
        {
            break;
        }
        
        potezKompijutera(razmaci, kompijuter, igrac);
        kraj = porveriPobedu(razmaci, igrac, kompijuter);
        igranje = proveriNereseno(razmaci, kraj);
    }
    
    while (igranje == true)
    {
        if (gamemode != 3)
        {
            break;
        }
        potezKompijutera(razmaci, kompijuter, igrac);
        kraj = porveriPobedu(razmaci, igrac, kompijuter);
        igranje = proveriNereseno(razmaci, kraj);
        if (igranje == false)
        {
            break;
        }
        
        potezIgraca(razmaci, igrac);
        kraj = porveriPobedu(razmaci, igrac, kompijuter);        
        igranje = proveriNereseno(razmaci, kraj);
    }

    return 0;
}

void uputstva(){
    char jasno;
    std::cout << "Svako polje je odredjeni broj po sledecem principu: \n";
    std::cout << "     |     |     " << "\n";
    std::cout << "  7  |  8  |  9  " << "\n";
    std::cout << "_____|_____|_____" << "\n";
    std::cout << "     |     |     " << "\n";
    std::cout << "  4  |  5  |  6  " << "\n";
    std::cout << "_____|_____|_____" << "\n";
    std::cout << "     |     |     " << "\n";
    std::cout << "  1  |  2  |  3  " << "\n";
    std::cout << "     |     |     " << "\n";
    std::cout << "\n";
    std::cout << "Da li su pravila jasna?(D/N)";
    std::cin >> jasno;
    if (jasno == 'N' || jasno == 'n')
    {
        uputstva();
    }
}

void nacrtajTablu(char *razmaci){
    std::cout << "\n";
    std::cout << "     |     |     " << "\n";
    std::cout << "  " << razmaci[6] << "  |  " << razmaci[7] << "  |  " << razmaci[8] << "  " << "\n";
    std::cout << "_____|_____|_____" << "\n";
    std::cout << "     |     |     " << "\n";
    std::cout << "  " << razmaci[3] << "  |  " << razmaci[4] << "  |  " << razmaci[5] << "  " << "\n";
    std::cout << "_____|_____|_____" << "\n";
    std::cout << "     |     |     " << "\n";
    std::cout << "  " << razmaci[0] << "  |  " << razmaci[1] << "  |  " << razmaci[2] << "  " << "\n";
    std::cout << "     |     |     " << "\n";
    std::cout << "\n";
}

void potezIgraca(char *razmaci, char igrac){
    int broj;

    do{
    std::cout << "Izaberite broj izmedju 1 i 9: \n";
    std::cin >> broj;
    broj--;

    if (razmaci[broj] != ' ')
    {
        std::cout << "Mesto je vec zasuzeto, izaberite ponovo. \n";
        broj = 11;
    }
    
    }while (broj<0 || broj>8);    
    
    razmaci[broj] = igrac;
    nacrtajTablu(razmaci);
}

void potezIgraca2(char *razmaci, char kompijuter){
    int broj;

    do{
    std::cout << "Izaberite broj izmedju 1 i 9: \n";
    std::cin >> broj;
    broj--;

    if (razmaci[broj] != ' ')
    {
        std::cout << "Mesto je vec zasuzeto, izaberite ponovo. \n";
        broj = 11;
    }
    
    }while (broj<0 || broj>8);    
    
    razmaci[broj] = kompijuter;
    nacrtajTablu(razmaci);
}

void potezKompijutera(char *razmaci, char kompijuter, char igrac){
    int broj;

    if (((razmaci[1] == kompijuter && razmaci[2] == kompijuter) ||
        (razmaci[4] == kompijuter && razmaci[8] == kompijuter) ||
        (razmaci[3] == kompijuter && razmaci[6] == kompijuter)) && razmaci[0] == ' ')
    {
        razmaci[0] = kompijuter;
    }else if (((razmaci[4] == kompijuter && razmaci[7] == kompijuter) ||
              (razmaci[0] == kompijuter && razmaci[2] == kompijuter)) && razmaci[1] == ' ')
    {
        razmaci[1] = kompijuter;
    }else if (((razmaci[0] == kompijuter && razmaci[1] == kompijuter) ||
              (razmaci[6] == kompijuter && razmaci[4] == kompijuter) ||
              (razmaci[8] == kompijuter && razmaci[5] == kompijuter)) && razmaci[2] == ' ')
    {
        razmaci[2] = kompijuter;
    }else if (((razmaci[4] == kompijuter && razmaci[5] == kompijuter) ||
              (razmaci[0] == kompijuter && razmaci[6] == kompijuter)) && razmaci[3] == ' ')
    {
            razmaci[3] = kompijuter;
    }else if (((razmaci[0] == kompijuter && razmaci[8] == kompijuter) ||
              (razmaci[1] == kompijuter && razmaci[7] == kompijuter) ||
              (razmaci[2] == kompijuter && razmaci[6] == kompijuter) ||
              (razmaci[3] == kompijuter && razmaci[5] == kompijuter)) && razmaci[4] == ' ')
    {
        razmaci[4] = kompijuter;
    }else if (((razmaci[3] == kompijuter && razmaci[4] == kompijuter) ||
              (razmaci[2] == kompijuter && razmaci[8] == kompijuter)) && razmaci[5] == ' ')
    {
        razmaci[5] = kompijuter;
    }else if (((razmaci[0] == kompijuter && razmaci[3] == kompijuter) ||
              (razmaci[2] == kompijuter && razmaci[4] == kompijuter) ||
              (razmaci[8] == kompijuter && razmaci[7] == kompijuter)) && razmaci[6] == ' ')
    {
        razmaci[6] = kompijuter;
    }else if (((razmaci[1] == kompijuter && razmaci[4] == kompijuter) ||
              (razmaci[6] == kompijuter && razmaci[8] == kompijuter)) && razmaci[7] == ' ')
    {
        razmaci[7] = kompijuter;
    }else if (((razmaci[6] == kompijuter && razmaci[7] == kompijuter) ||
              (razmaci[0] == kompijuter && razmaci[4] == kompijuter) ||
              (razmaci[2] == kompijuter && razmaci[5] == kompijuter)) && razmaci[8] == ' ')
    {
        razmaci[8] = kompijuter;
    }else if (((razmaci[1] == igrac && razmaci[2] == igrac) ||
              (razmaci[4] == igrac && razmaci[8] == igrac) ||
              (razmaci[3] == igrac && razmaci[6] == igrac)) && razmaci[0] == ' ')
    {
        razmaci[0] = kompijuter;
    }else if (((razmaci[4] == igrac && razmaci[7] == igrac) ||
              (razmaci[0] == igrac && razmaci[2] == igrac)) && razmaci[1] == ' ')
    {
        razmaci[1] = kompijuter;
    }else if (((razmaci[0] == igrac && razmaci[1] == igrac) ||
              (razmaci[6] == igrac && razmaci[4] == igrac) ||
              (razmaci[8] == igrac && razmaci[5] == igrac)) && razmaci[2] == ' ')
    {
        razmaci[2] = kompijuter;
    }else if (((razmaci[4] == igrac && razmaci[5] == igrac) ||
              (razmaci[0] == igrac && razmaci[6] == igrac)) && razmaci[3] == ' ')
    {
        razmaci[3] = kompijuter;
    }else if (((razmaci[0] == igrac && razmaci[8] == igrac) ||
              (razmaci[1] == igrac && razmaci[7] == igrac) ||
              (razmaci[2] == igrac && razmaci[6] == igrac) ||
              (razmaci[3] == igrac && razmaci[5] == igrac)) && razmaci[4] == ' ')
    {   
        razmaci[4] = kompijuter;
    }else if (((razmaci[3] == igrac && razmaci[4] == igrac) ||
              (razmaci[2] == igrac && razmaci[8] == igrac)) && razmaci[5] == ' ')
    {
        razmaci[5] = kompijuter;
    }else if (((razmaci[0] == igrac && razmaci[3] == igrac) ||
              (razmaci[2] == igrac && razmaci[4] == igrac) ||
              (razmaci[8] == igrac && razmaci[7] == igrac)) && razmaci[6] == ' ')
    {
        razmaci[6] = kompijuter;
    }else if (((razmaci[1] == igrac && razmaci[4] == igrac) ||
              (razmaci[6] == igrac && razmaci[8] == igrac)) && razmaci[7] == ' ')
    {
        razmaci[7] = kompijuter;
    }else if (((razmaci[6] == igrac && razmaci[7] == igrac) ||
              (razmaci[0] == igrac && razmaci[4] == igrac) ||
              (razmaci[2] == igrac && razmaci[5] == igrac)) && razmaci[8] == ' ')
    {
        razmaci[8] = kompijuter;
    }else{
        srand(time(NULL));
        do{
            broj = rand() % 9;
        }while(razmaci[broj] != ' ');
        razmaci[broj] = kompijuter;
    }
    
    nacrtajTablu(razmaci);
}

bool porveriPobedu(char *razmaci, char igrac, char kompijuter){
    if ((razmaci[0] == igrac && razmaci[1] == igrac && razmaci[2] == igrac) || 
        (razmaci[3] == igrac && razmaci[4] == igrac && razmaci[5] == igrac) || 
        (razmaci[6] == igrac && razmaci[7] == igrac && razmaci[8] == igrac) ||
        (razmaci[0] == igrac && razmaci[3] == igrac && razmaci[6] == igrac) ||
        (razmaci[1] == igrac && razmaci[4] == igrac && razmaci[7] == igrac) ||
        (razmaci[2] == igrac && razmaci[5] == igrac && razmaci[8] == igrac) ||
        (razmaci[0] == igrac && razmaci[4] == igrac && razmaci[8] == igrac) ||
        (razmaci[6] == igrac && razmaci[4] == igrac && razmaci[2] == igrac))
    {
        std::cout << "***************************** \n";
        std::cout << "***       POBEDA!!!       *** \n";
        std::cout << "***************************** \n";
        return true;
    }else if ((razmaci[0] == kompijuter && razmaci[1] == kompijuter && razmaci[2] == kompijuter) || 
              (razmaci[3] == kompijuter && razmaci[4] == kompijuter && razmaci[5] == kompijuter) || 
              (razmaci[6] == kompijuter && razmaci[7] == kompijuter && razmaci[8] == kompijuter) ||
              (razmaci[0] == kompijuter && razmaci[3] == kompijuter && razmaci[6] == kompijuter) ||
              (razmaci[1] == kompijuter && razmaci[4] == kompijuter && razmaci[7] == kompijuter) ||
              (razmaci[2] == kompijuter && razmaci[5] == kompijuter && razmaci[8] == kompijuter) ||
              (razmaci[0] == kompijuter && razmaci[4] == kompijuter && razmaci[8] == kompijuter) ||
              (razmaci[6] == kompijuter && razmaci[4] == kompijuter && razmaci[2] == kompijuter))
    {
        std::cout << "***************************** \n";
        std::cout << "***       GAME OVER       *** \n";
        std::cout << "***************************** \n";
        return true;
    }
    
    return false;
}

bool proveriPobeduPVP(char *razmaci, char igrac, char kompijuter){
    if ((razmaci[0] == igrac && razmaci[1] == igrac && razmaci[2] == igrac) || 
        (razmaci[3] == igrac && razmaci[4] == igrac && razmaci[5] == igrac) || 
        (razmaci[6] == igrac && razmaci[7] == igrac && razmaci[8] == igrac) ||
        (razmaci[0] == igrac && razmaci[3] == igrac && razmaci[6] == igrac) ||
        (razmaci[1] == igrac && razmaci[4] == igrac && razmaci[7] == igrac) ||
        (razmaci[2] == igrac && razmaci[5] == igrac && razmaci[8] == igrac) ||
        (razmaci[0] == igrac && razmaci[4] == igrac && razmaci[8] == igrac) ||
        (razmaci[6] == igrac && razmaci[4] == igrac && razmaci[2] == igrac))
    {
        std::cout << "*************************************** \n";
        std::cout << "***       IGRAC #1 JE POBEDIO       *** \n";
        std::cout << "*************************************** \n";
        return true;
    }else if ((razmaci[0] == kompijuter && razmaci[1] == kompijuter && razmaci[2] == kompijuter) || 
              (razmaci[3] == kompijuter && razmaci[4] == kompijuter && razmaci[5] == kompijuter) || 
              (razmaci[6] == kompijuter && razmaci[7] == kompijuter && razmaci[8] == kompijuter) ||
              (razmaci[0] == kompijuter && razmaci[3] == kompijuter && razmaci[6] == kompijuter) ||
              (razmaci[1] == kompijuter && razmaci[4] == kompijuter && razmaci[7] == kompijuter) ||
              (razmaci[2] == kompijuter && razmaci[5] == kompijuter && razmaci[8] == kompijuter) ||
              (razmaci[0] == kompijuter && razmaci[4] == kompijuter && razmaci[8] == kompijuter) ||
              (razmaci[6] == kompijuter && razmaci[4] == kompijuter && razmaci[2] == kompijuter))
    {
        std::cout << "*************************************** \n";
        std::cout << "***       IGRAC #2 JE POBEDIO       *** \n";
        std::cout << "*************************************** \n";
        return true;
    }
    
    return false;
}

bool proveriNereseno(char *razmaci, bool kraj){

    if (kraj == true)
    {
        return false;
    }
    
    for (int i = 0; i < 9; i++)
    {
        if (razmaci[i] == ' ')
        {
            return true;
        }
    }
    
    std::cout << "***************************** \n";
    std::cout << "***       NERESENO!       *** \n";
    std::cout << "***************************** \n";

    return false;
}
