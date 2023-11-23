//
// Created by Павел on 23.11.2023.
//

#ifndef LAB4_POSTOFFICE_H
#define LAB4_POSTOFFICE_H


class PostOffice {
private:
    int index;
    int mails;
public:
    const int getIndex() const;
    const int getMails() const;

    PostOffice();
    PostOffice(int index, int mails);
};


#endif //LAB4_POSTOFFICE_H
