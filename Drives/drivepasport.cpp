#include "drivepasport.h"

namespace Drives
{
    void DrivePasport::Initialize()
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
            CreateFile(tmp->c_str(),
                       GENERIC_READ,
                       FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                       nullptr,
                       OPEN_EXISTING,
                       FILE_ATTRIBUTE_NORMAL,
                       nullptr);
        if(hDrive != INVALID_HANDLE_VALUE)
            break;

        this->_ddInfoData->push_back(DriveData(idDrive));


            delete tmp;
        }
        while(hDrive != INVALID_HANDLE_VALUE);
        this->_isInitilized = true;
    }
}
