//
// Created by Павел on 23.11.2023.
//

#include "PostOffice.h"

const int PostOffice::getIndex() const{
    return index;
}

const int PostOffice::getMails() const{
    return mails;
}

PostOffice::PostOffice() {
    index = 0;
    mails = 0;
}

PostOffice::PostOffice(int index, int mails) {
    this->index = index;
    this->mails = mails;
}
