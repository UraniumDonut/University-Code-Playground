//new struct Koerper with mass, position and speed
struct Koerper {
    int masse;
    int position[2];
    int geschwindigkeit[2];
};



int main()
{
    // Körper:
    Koerper koerper;
    koerper.masse = 10;
    koerper.position = {0, 0};
    koerper.geschwindigkeit = {10, 10};
    // Parametrierung der auf den Körper wirkende Kräfte:
    const Vektor BESCHLEUNIGUNG_GRAVITATION = {0, -9.81}; // [m/s^2]
    const float REIBUNGSKOEFFIZIENT = -5;                 // [kg/s]
    // Sorgt dafür, dass 2 Nachkommastellen angezeigt werden:
    cout << fixed;
    cout.precision(2);
    // Simulation:
    const float dt = 0.1;
    for (;;)
    {
        cout << "Position des Körpers: ";
        ausgabeKoerper(koerper);
        2 cout << endl;
        // Bestimmung der Kraft
        Vektor reibungskraft = mulVektor(koerper.geschwindigkeit,
                                         REIBUNGSKOEFFIZIENT);
        Vektor anziehungskraft = mulVektor(BESCHLEUNIGUNG_GRAVITATION,
                                           koerper.masse);
        Vektor gesamtkraft = addVektor(reibungskraft, anziehungskraft);
        // Ermittlung der neuen Position und neuen Geschwindigkeit
        bewegeKoerper(koerper, gesamtkraft, dt);
        if (koerper.position.y <= 0)
        {
            break;
        }
    }
}
