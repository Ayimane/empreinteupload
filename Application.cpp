#include "Application.hpp"

Application::Application() : fingerprintSensor(p13, p14), ledController(p24, p25) {
    // Initialisation d'autres composants si nécessaire
}

void Application::run() {
     
     ledController.turnOff();  // Éteindre l'anneau de LED

    // Enregistrement de l'empreinte au démarrage (peut être fait une seule fois)
    fingerprintSensor.enrollFingerprint();
    ledController.turnOnGreen();
  

    while (1) {
        // Scan de l'empreinte
        if (fingerprintSensor.scanFingerprint()) {
            // Empreinte reconnue, allumez l'anneau de LED en vert
            ledController.turnOnGreen();
        } else {
            // Empreinte non reconnue, allumez l'anneau de LED en rouge
            ledController.turnOnRed();
        }

        wait_us(200);  // Attendre avant la prochaine tentative 5sec
        ledController.turnOff();  // Éteindre l'anneau de LED
    }
}
