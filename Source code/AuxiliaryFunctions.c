#include "AuxiliaryFunctions.h"


int printMenu(void)
{
    int action = MENU_DEFAULT;
    /*while (action < 0 && action>12)*/
    /*{*/
    printf("\tMENU:\n\n\
      0. Exit Program\n\n\
      1. Admit Patient\n\n\
      2. Check fot patient's allergies\n\n\
      3. Dispaly all patients\n\n\
      4. Dispaly all patient's admission\n\n\
      5. Dispaly all patients in line\n\n\
      6. Advance patient in line\n\n\
      7. Display list of all doctors\n\n\
      8. Display all patients assigned to a doctor\n\n\
      9. Discharge patient\n\n\
      10. Remove visit\n\n\
      11. Remove patient\n\n\
      12. Close the hospital\n");
    /*}*/

    return action;
}

void loadPatients()
{
    FILE* PtrPatients = fopen("Patients.txt", "rb");
}
