#pragma once
#include <Windows.h>
#include <vector>
#include <string>
#include "Drives/drivedata.h"
#include <QMessageBox>
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

        void Initialize()
        {

            if(this->_ddInfoData)
                delete this->_ddInfoData;

            this->_ddInfoData = new std::vector<DriveData>();
            const std::wstring BASE_PATH(L"\\\\.\\PhysicalDrive");
            HANDLE hDrive = nullptr;
            std::size_t idDrive = 0;

            do
            {
                std::wstring* tmp = new std::wstring(BASE_PATH);
                tmp->append(std::to_wstring(idDrive));
                hDrive = CreateFile(tmp->c_str(),
                           GENERIC_WRITE,
                           FILE_SHARE_READ,
                           nullptr,
                           OPEN_EXISTING,
                           FILE_ATTRIBUTE_NORMAL,
                           nullptr);
                if(hDrive == INVALID_HANDLE_VALUE)
                    break;

                this->_ddInfoData->push_back(DriveData(idDrive++));
                delete tmp;
            }
            while(true);
            this->_isInitilized = true;

        }

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
