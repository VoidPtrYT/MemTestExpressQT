#ifndef DRIVEPASPORT_H
#define DRIVEPASPORT_H

#include <Windows.h>
#include <vector>
#include <string>
#include "Drives/drivedata.h"

namespace Drives
{
    class DrivePasport
    {
    private:
        std::vector<DriveData>* _ddInfoData = nullptr;
        bool _isInitilized = false;

    public:
        ///CTOR
        DrivePasport() = default;

        const std::size_t GetCountDrives() const
        {
            return this->_ddInfoData->size();
        }

        const bool IsInitialized() const
        {
            return this->_isInitilized;
        }

        void Initialize();

        ///DTOR
        ~DrivePasport()
        {
            if(this->_ddInfoData)
            {
                delete this->_ddInfoData;
                this->_ddInfoData = nullptr;
            }
        }
    };
}
#endif // DRIVEPASPORT_H
