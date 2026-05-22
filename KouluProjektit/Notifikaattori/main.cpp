#include <iostream>
#include "Notifikaattori.h"
#include "Seuraaja.h"

using namespace std;

int main()
{
    Notifikaattori notif;
    Seuraaja follower("Matti");
    Seuraaja follower2("Heppo");
    Seuraaja follower3("Teppo");
    notif.lisaa(&follower);
    notif.lisaa(&follower2);
    notif.lisaa(&follower3);
    notif.poista(&follower);

    notif.tulosta();
    notif.postita("Paskaa");
    return 0;
}
