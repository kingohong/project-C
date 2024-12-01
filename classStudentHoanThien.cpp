#include <iostream>
#include <string.h>
using namespace std;
class Date
{
public:
    bool setDate (int ngay, int thang, int nam)
    {
        if (nam<0)
        {
            return false;
        }
        else
        {
            if (thang<1 || thang>12)
            {
                return false;
            }
            else
            {
                if(thang==1 || thang==3 || thang==5 || thang==7 || thang==8 || thang==10 || thang==12)
                {
                    if (ngay<1 || ngay>31)
                    {
                        return false;
                    }
                }
                else if (thang==4 || thang==6 || thang==9 || thang==11)
                {
                    if (ngay<1 || ngay>30)
                    {
                        return false;
                    }
                }
                else if (thang==2)
                {
                    if (nam%4==0 && (nam%400==0 || nam%100!=0))
                    {
                        if (ngay<1 || ngay>29)
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if (ngay<1 || ngay>28)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    void input()
    {
        do
        {
            cin >> this->ngay >> this->thang >> this->nam;
        }
        while (setDate(this->ngay, this->thang, this->nam)==false);
    }

    void display()
    {
        cout << "Birth date: " << this->ngay << "-" << this->thang << "-" << this->nam << endl;
    }

private:
    int ngay, thang, nam;
};
class Student
{
public:
    void xoaKhoangTrang(char chuoi[])
    {
        int doDai = strlen(chuoi);
        for (int i=0; i<doDai; i++)
        {
            if(chuoi[0]==' ')
            {
                for (int j=0; j<doDai; j++)
                {
                    chuoi[j] = chuoi[j+1];
                }
                doDai--;
                i--;
            }
            else if (chuoi[i]==' ' && chuoi[i+1]==' ')
            {
                for (int j=i+1; j<doDai; j++)
                {
                    chuoi[j]=chuoi[j+1];
                }
                doDai--;
                i--;
            }
        }
    }

    void dinhDang (char chuoi[])
    {
        int doDai=strlen(chuoi);
        for (int i=0; i<doDai; i++)
        {
            if (chuoi[0]>='a' && chuoi[0]<='z')
            {
                chuoi[0] = chuoi[0] - 32;
            }
            if (chuoi[i-1]==' ' && chuoi[i] >= 'a' && chuoi[i]  <= 'z')
            {
                chuoi[i] = chuoi[i] - 32;
            }
            else if (chuoi[i]>='A' && chuoi[i] <='Z' && chuoi[i-1]!=' ')
            {
                chuoi[i] = chuoi[i] + 32;
            }
        }
    }

    void setDetail (string id, string fullName, string address)
    {
        int a=id.length();
        for (int i=0; i<a; i++)
        {
            this->id[i] = id[i];
        }
        this->id[a] = '\0';
        int b=fullName.length();
        for (int i=0; i<b; i++)
        {
            this->fullName[i] = fullName[i];
        }
        this->fullName[b] = '\0';
        int c=address.length();
        for (int i=0; i<c; i++)
        {
            this->address[i] = address[i];
        }
        this->address[c] = '\0';
    }

    void input()
    {
        string id;
        string fullName;
        string address;

        getline(cin, id);
        getline(cin, fullName);
        ngaySinh.input();
        cin.ignore();
        getline(cin, address);

        setDetail(id, fullName, address);
    }

    string getFullName()
    {
        xoaKhoangTrang(this->fullName);
        dinhDang(this->fullName);
        return this->fullName;
    }

    string getAddress()
    {
        xoaKhoangTrang(this->address);
        dinhDang(this->address);
        return this->address;
    }

    string tachHo()
    {
        int heSo=0;
        int a=strlen(this->fullName);
        for (int i=0; i<a; i++)
        {
            if (fullName[i]==' ')
            {
                break;
            }
            heSo++;
        }
        for (int i=0; i<heSo; i++)
        {
            this->ho[i] = this->fullName[i];
        }
        this->ho[heSo] = '\0';
        return this->ho;
    }

    string tachTen()
    {
        int heSo=0;
        int a=strlen(this->fullName);
        for (int i=a-1; i>0; i--)
        {
            if (fullName[i]==' ')
            {
                heSo = i+1;
                break;
            }
        }
        for (int i=0; i<a; i++)
        {
            if (heSo==a)
            {
                break;
            }
            this->ten[i] = this->fullName[heSo];
            heSo++;
        }
        this->ten[a] = '\0';
        return this->ten;
    }

    void display()
    {
        cout << "Full name: " << getFullName() << endl;
        cout << "First name: " << tachHo() << endl;
        cout << "Last name: " << tachTen() << endl;
        ngaySinh.display();
        cout << "Address: " << getAddress() << endl;
    }

private:
    char id[100], fullName[100], address[100], ho[50], ten[50];
    Date ngaySinh;
};
int main()
{
    Student st;
    st.input();
    st.display();
    return 0;
}

