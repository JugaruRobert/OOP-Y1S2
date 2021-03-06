//
// Created by Sorin Sebastian Mircea on 08/03/2017.
//

#include <cxxabi.h>
#include <stdlib.h>
#include <string.h>
#include "MedRepository.h"

MedRepository *createRepository() {
    /*
     * Make the Medications Repository
     */
    MedRepository* newRepo = (MedRepository*) malloc(sizeof(MedRepository));

    newRepo->medications = (Medication**) malloc(sizeof(Medication*) * 100);
    newRepo->length = 0;

    return newRepo;
}

void destroyRepo(MedRepository *medRepo) {

    //1st free the parameters
    free(medRepo->medications);

    //then free the object itself
    free(medRepo);
}

int getLengthR(MedRepository *medRepo) {
    /*
     * Return the length of the repository
     */
    return medRepo->length;
}

MedRepository *addMedicationR(MedRepository *medRepo, Medication *medObj) {
/*
     * @param medRepo: a pointer to the actual repository
     * @param medObj
     */

    //To do - check if medication already exists

    medRepo->length = medRepo->length + 1;
    medRepo->medications[medRepo->length] = medObj;

    return medRepo;
}


int doesMedExistsR(MedRepository *medRepository, char *name, double concentration) {
    /*
     *  @param medRepository: pointer to medRepository
     *  @param name: char pointer
     *  @param concentration: concentration
     *  Return 1 if the given med is in repository, 0 otherise
     */
    int i;

    for(i = 1; i <= medRepository->length; i++)
        if(strcmp(medRepository->medications[i]->name, name) == 0 && medRepository->medications[i]->concentration == concentration)
            return 1;
    return 0;
}

MedRepository *updateMedicationR(MedRepository *medRepository, char *orgName, double orgConcentration, char *name,
                                 double concentration, int quantity, int price) {
    /*
     *  @param medRepository: pointer to medRepository
     *  @param orgName: char pointer to old name
     *  @param orgConcentration: old concentration
     *  @param name: new name
     *  @param concentration: new concentration
     *  @param quantity: new quantity
     *  @param price: new price
     *  Updates a medication accordingly
     */
    int i;

    for(i = 1; i <= medRepository ->length; i++)
        if(strcmp(medRepository->medications[i]->name, orgName) == 0 && medRepository->medications[i]->concentration == orgConcentration) {
            medRepository->medications[i] = createMedication(name, concentration, quantity, price);
        }

    return medRepository;
}

Medication *getMedR(MedRepository *medRepository, char *name, double concentration) {
    /*
     *  @param medRepository: pointer to medRepository
     *  @param name: char pointer
     *  @param concentration: concentration
     *  Return a Medication object if it is found, zero othwerwise
     */
    int i;

    for(i = 1; i <= medRepository->length; i++)
        if(strcmp(medRepository->medications[i]->name, name) == 0 && medRepository->medications[i]->concentration == concentration) {
            return medRepository->medications[i];
        }

    return 0;
}

MedRepository *deleteMedicationR(MedRepository *medRepository, char *name, double concentration) {
    /*
     *  @param medRepository: pointer to medRepository
     *  @param name: char pointer
     *  @param concentration: concentration
     *  Delete a medication from repository
     */
    int i;
    int ok = 0;

    for(i = 1; i <= medRepository -> length; i++) {
        if(strcmp(medRepository->medications[i]->name, name) == 0 && medRepository->medications[i]->concentration == concentration) {
            ok = 1;
        }

        if( ok == 1 )
            medRepository -> medications[i] = medRepository -> medications[i+1];
    }

    if( ok == 1 )
        medRepository -> length = medRepository -> length - 1;

    return medRepository;
}
