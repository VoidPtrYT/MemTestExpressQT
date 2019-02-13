#ifndef DRIVESTRUCT_H
#define DRIVESTRUCT_H

namespace Drives
{
    ///Provides data for technology S.M.A.R.T.
    struct SMARTData
    {
        ///ID of param
        int _id = 0;
        ///Value of param
        int _value = 0;
        ///Worst value
        int _worst = 0;
        ///Threshold(пороговое) value
        int _threshold = 0;
        ///Data of param
        unsigned long long _data = 0UL;
        ///Flag of status
        int _statusFlag = 0;
    };
}

#endif // DRIVESTRUCT_H
