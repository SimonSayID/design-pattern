//
// Created by Simon on 2017/10/21.
//

#ifndef DESIGN_PATTERN_FACADE_H
#define DESIGN_PATTERN_FACADE_H

#include "../../main.h"

namespace facade {

    class MisDepartment {
    public:
        void submitNetworkRequest();
        bool checkOnStatus();

    private:
        enum States {
            Received, DenyAllKnowledge, ReferClientToFacilities,
            FacilitiesHasNotSentPaperwork, ElectricianIsNotDone,
            ElectricianDidItWrong, DispatchTechnician, SignedOff, DoesNotWork,
            FixElectriciansWiring, Complete
        };
        int _state;
    };

    class ElectricianUnion {
    public:
        void submitNetworkRequest();
        bool checkOnStatus();

    private:
        enum States {
            Received, RejectTheForm, SizeTheJob, SmokeAndJokeBreak,
            WaitForAuthorization, DoTheWrongJob, BlameTheEngineer, WaitToPunchOut,
            DoHalfAJob, ComplainToEngineer, GetClarification, CompleteTheJob,
            TurnInThePaperwork, Complete
        };
        int _state;
    };

    class FacilitiesDepartment {
    public:
        void submitNetworkRequest();
        bool checkOnStatus();

    private:
        enum States {
            Received, AssignToEngineer, EngineerResearches, RequestIsNotPossible,
            EngineerLeavesCompany, AssignToNewEngineer, NewEngineerResearches,
            ReassignEngineer, EngineerReturns, EngineerResearchesAgain,
            EngineerFillsOutPaperWork, Complete
        };
        int _state;
    };

    class FacilitiesFacade {
    public:
        FacilitiesFacade();
        void submitNetworkRequest();
        bool checkOnStatus();
        int getNumberOfCalls();

    private:
        enum States {
            Received, SubmitToEngineer, SubmitToElectrician, SubmitToTechnician
        };
        int _state;
        int _count;
        FacilitiesDepartment _engineer;
        ElectricianUnion _electrician;
        MisDepartment _technician;
    };
}

#endif //DESIGN_PATTERN_FACADE_H
