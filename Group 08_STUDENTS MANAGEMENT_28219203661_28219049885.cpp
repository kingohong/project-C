#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
struct password
{
    string tenDangKy;
    int matKhauDangKy;
};
typedef struct password PASSWORD;
void ghiKiTuXuongDong()
{
    ofstream fo("DuLieuSinhVien.txt", ios::app);
    fo << "\n";
    fo.close();
}
void ghiKiTuXuongDongPw()
{
    ofstream fo("PassWord.txt", ios::app);
    fo << "\n";
    fo.close();
}
void ghiPassWordVaoFile(PASSWORD pw)
{
    ofstream fo("PassWord.txt", ios::app);
    fo << pw.tenDangKy << "-";
    fo << pw.matKhauDangKy;
    fo.close();
}
void ghiFileSoluong(int& n)
{
    ofstream os("SoLuong.txt");
    os << n;
    os.close();

}
void docFileSoLuong(int& n)
{
    int soLuong;
    ifstream is("SoLuong.txt");
    is >> soLuong;
    n = soLuong;
}
void ghiFileSoLuongPw(int& soLuong)
{
    ofstream fo("SoLuongPassWord.txt");
    fo << soLuong;
    fo.close();
}
void docFileSoLuongPw(int& soLuong)
{
    int size = 0; ;
    ifstream fi("SoLuongPassWord.txt");
    fi >> size;
    soLuong = size;
    fi.close();

}
bool kiemTraAsciiPassWord(string passWord)
{
    for (int i = 0; i < passWord.length(); i++)
    {
        if (passWord[i] >= 48 && passWord[i] <= 57)
        {
            return false;
        }
    }
    return true;
}
bool kiemTraAsciiTen(char hoTen[])
{
    for (int i = 0; i < strlen(hoTen); i++)
    {
        if (hoTen[i] >= 48 && hoTen[i] <= 57)
        {
            return false;
        }
    }
    return true;
}
void nhanPhimEnter()
{
    cout << "\n\n";
    cout << "* Nhan phim enter de tiep tuc *";
}
void nhapPassWord(PASSWORD& pw, int& soLuong)
{
    cout << "      - DANG KY -" << "\n";
    cout << "Nhap ten dang ky:";
    getline(cin, pw.tenDangKy);
    cout << "Nhap mat khau dang ky:";
    cin >> pw.matKhauDangKy;
}

bool chinhTenTaiKhoan(string s)
{
    int soLuong = s.length();
    for (int i = 0; i < soLuong; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            return false;
        }
        else
        {
            return true;
        }

    }
}
bool chinhTenMonHoc(string& s)
{
    int soLuong = s.length();
    if (s[0] >= 'A' && s[0] <= 'Z')
    {
        return true;
    }
    for (int i = 1; i < soLuong; i++)
    {
        if (s[i - 1] == ' ')
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (s[i] >= 'a' && s[i] < 'z')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
void docPassWordTuFile(PASSWORD dsPW[], int& soLuong)
{
    soLuong = 0;
    ifstream fi("PassWord.txt");
    while (fi.eof() == false)
    {
        PASSWORD tam;
        getline(fi, tam.tenDangKy, '-');
        fi >> tam.matKhauDangKy;
        dsPW[soLuong] = tam;
        soLuong++;
    }
    fi.close();
}
bool kiemTraTenDangKy(string tenDk, int& soLuong)
{
    PASSWORD pw[100];
    docPassWordTuFile(pw, soLuong);
    for (int i = 0; i < soLuong; i++)
    {
        if (pw[i].tenDangKy == tenDk)
        {
            return false;
        }
    }
    return true;
}
void nhapDsPassWord(PASSWORD pW, int& soLuong)
{
    ++soLuong;
    ghiFileSoLuongPw(soLuong);
    docFileSoLuongPw(soLuong);
    if (soLuong == 1)
    {
        do
        {
            system("cls");
            cin.ignore();
            nhapPassWord(pW, soLuong);
            system("cls");
            if (pW.tenDangKy.length() > 50 || pW.matKhauDangKy < 1000 || pW.matKhauDangKy > 10000)
            {
                cout << "                          DANG KY TAI KHOAN KHONG THANH CONG VUI LONG NHAP LAI!" << "\n\n";
                cout << "-> Can nhap ten dang ky co kich thuoc nho hon 50 va mat khau co 4 chu so !";
                system("pause");
                system("cls");
            }
            if (kiemTraTenDangKy(pW.tenDangKy, soLuong) == false)
            {
                cout << "                          DANG KY TAI KHOAN KHONG THANH CONG VUI LONG NHAP LAI!" << "\n\n";
                cout << "-> Ten dang ky tren da ton tai ,  vui long dang ky ten khac !";
                system("pause");
                system("cls");
            }
            if (kiemTraAsciiPassWord(pW.tenDangKy) == false)
            {
                cout << "                          DANG KY TAI KHOAN KHONG THANH CONG VUI LONG NHAP LAI!" << "\n\n";
                cout << "-> Ten dang ky tren khong chua so tu 0 -> 9 ,  vui long dang ky ten khac !";
                system("pause");
                system("cls");
            }
        } while (pW.tenDangKy.length() > 50 > 50 || pW.matKhauDangKy < 1000 || pW.matKhauDangKy > 10000 || kiemTraTenDangKy(pW.tenDangKy, soLuong) == false || kiemTraAsciiPassWord(pW.tenDangKy) == false);

    }
    else
    {
        ghiKiTuXuongDongPw();
        do
        {
            system("cls");
            cin.ignore();
            nhapPassWord(pW, soLuong);
            system("cls");
            if (pW.tenDangKy.length() > 50 || pW.matKhauDangKy < 1000 || pW.matKhauDangKy > 10000)
            {
                cout << "                          DANG KY TAI KHOAN KHONG THANH CONG VUI LONG NHAP LAI!" << "\n\n";
                cout << "-> Can nhap ten dang ky co dai nho hon 50 va mat khau co 4 chu so !";
                system("pause");
                system("cls");
            }
            if (kiemTraTenDangKy(pW.tenDangKy, soLuong) == false)
            {
                cout << "                          DANG KY TAI KHOAN KHONG THANH CONG VUI LONG NHAP LAI!" << "\n\n";
                cout << "-> Ten dang ky tren da ton tai ,  vui long dang ky ten khac !";
                system("pause");
                system("cls");
            }
            if (kiemTraAsciiPassWord(pW.tenDangKy) == false)
            {
                cout << "                          DANG KY TAI KHOAN KHONG THANH CONG VUI LONG NHAP LAI!" << "\n\n";
                cout << "-> Ten dang ky tren khong chua so tu 0 -> 9 ,  vui long dang ky ten khac !";
                system("pause");
                system("cls");
            }

        } while (pW.tenDangKy.length() > 50 || pW.matKhauDangKy < 1000 || pW.matKhauDangKy > 10000 || kiemTraTenDangKy(pW.tenDangKy, soLuong) == false || kiemTraAsciiPassWord(pW.tenDangKy) == false);
    }
    ghiPassWordVaoFile(pW);
    cout << "                                       DANG KY TAI KHOAN THANH CONG !" << "\n";
    system("pause");
    system("cls");
}
struct sinhvien
{
    char hoTen[30];
    string gioiTinh;
    int mssv;
    int ngay, thang, nam;
    string tenMon1, tenMon2, tenMon3;
    float diemMon1, diemMon2, diemMon3;
    float diemTb;
    string queQuan;
};
typedef struct sinhvien SINHVIEN;
bool kiemTraDate(int ngay, int thang, int nam)
{
    if (thang >= 12 || nam <= 0 || ngay > 31)
    {
        return false;
    }
    else
    {
        if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
        {
            if (ngay <= 31)
            {
                return true;
            }
            else
            {
                return false;
            }

        }
        else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
        {
            if (ngay <= 30)
            {
                return true;

            }
            else
            {
                return false;
            }
        }
        else if (thang == 2)
        {
            if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0)
            {
                if (ngay <= 29)
                {
                    return true;

                }
                else
                {
                    return false;
                }
            }
            else if (nam % 4 != 0 && nam % 100 == 0 || nam % 400 != 0 && nam > 0)
            {
                if (ngay <= 28)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
}
bool chinhTen(char s[])
{
    int soLuong = strlen(s);
    if (s[0] >= 'a' && s[0] <= 'z')
    {
        return false;
    }
    else
    {
        return true;
    }
    for (int i = 1; i < soLuong; i++)
    {
        if (s[i - 1] == ' ')
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}
bool chinhSpaceCuaTen(char s[])
{
    int soLuong = strlen(s);
    while (s[0] == ' ')
    {
        return false;
    }
    while (s[soLuong] == ' ')
    {
        return false;
    }
    for (int i = 1; i < soLuong; i++)
    {
        if (s[i] == ' ' && s[i + 1] == ' ')
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
void ghiFile(SINHVIEN sv, int& n)
{
    ofstream fo("DuLieuSinhVien.txt", ios::app);

    fo << sv.hoTen << ",";
    fo << sv.mssv << ",";
    fo << sv.ngay << "/";
    fo << sv.thang << "/";
    fo << sv.nam << ",";
    fo << sv.gioiTinh << ",";
    fo << sv.queQuan << ",";
    fo << sv.diemTb;
    fo.close();
}
void ghiFileChucNang(SINHVIEN ds[], int& n)
{
    ofstream fo("DuLieuSinhVien.txt", ios::app);
    for (int i = 0; i < n; i++)
    {
        fo << ds[i].hoTen << ",";
        fo << ds[i].mssv << ",";
        fo << ds[i].ngay << "/";
        fo << ds[i].thang << "/";
        fo << ds[i].nam << ",";
        fo << ds[i].gioiTinh << ",";
        fo << ds[i].queQuan << ",";
        fo << ds[i].diemTb;
        if (i + 1 != n)
        {
            fo << "\n";
        }
    }
    fo.close();
}
void docFile(SINHVIEN ds[], int& n)
{
    n = 0;
    ifstream fi("DuLieuSinhVien.txt");
    SINHVIEN tam;
    while (fi.eof() == false)
    {
        fi.getline(tam.hoTen, 30, ',');
        fi >> tam.mssv;
        fi.ignore();
        fi >> tam.ngay;
        fi.ignore();
        fi >> tam.thang;
        fi.ignore();
        fi >> tam.nam;
        fi.ignore();
        getline(fi, tam.gioiTinh, ',');
        getline(fi, tam.queQuan, ',');
        fi >> tam.diemTb;
        fi.ignore();
        ds[n++] = tam;
    }
    fi.close();
}
void xoaToanBoFile()
{
    ofstream file("DuLieuSinhVien.txt", ofstream::out | ofstream::trunc);
    file.close();
}
bool kiemTraMaSinhVien(int ms, int& n)
{
    SINHVIEN ds[100];
    docFile(ds, n);
    for (int i = 0; i < n; i++)
    {
        if (ds[i].mssv == ms)
        {
            return false;
        }
    }
    return true;
}
bool isMatch(string tinh, string tt[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (tinh == tt[i])
        {
            return true;
        }
    }

    return false;
}
void nhap(SINHVIEN& sv, int& n)
{
    bool check = true;
    string dsTinhThanh[64] = { "Ha Giang"
       , "Cao Bang"
       , "Lao Cai"
       ,  "Son La"
     , "Lai Chau"
      , "Bac Kan"
        ,"Lang Son"
      ,"Tuyen Quang"
       ,"Yen Bai"
        ,"Thai Nguyen"
       ,"Đien Bien"
      ,"Phu Tho"
        ,"Vinh Phuc"
     ,"Bac Giang"
        ,"Bac Ninh"
        ,"Ha Noi"
        ,"Quang Ninh"
       ,"Hai Duong"
       ,"Hai Phong"
       ,"Hoa Binh"
       ,"Hung Yen"
       ,"Ha Nam"
      ,"Thai Binh"
        ,"Nam Đinh"
        ,"Ninh Binh"
       ,"Thanh Hoa"
        ,"Nghe An"
       ,"Ha Tinh"
        ,"Quang Binh"
        ,"Quang Tri"
       ,"Thua Thien Hue"
       ,"Đa Nang"
       ,"Quang Nam"
        ,"Quang Ngai"
       ,"Kon Tum"
      ,"Gia Lai"
        ,"Binh Đinh"
      ,"Phu Yen"
      ,"Đak Lak"
      ,"Khanh Hoa"
        ,"Đak Nong"
        ,"Lam Đong"
       ,"Ninh Thuan"
       ,"Binh Phuoc"
       ,"Tay Ninh"
     ,"Binh Duong"
        ,"Đong Nai"
       ,"Binh Thuan"
      ,"Thanh pho Ho Chi Minh"
      ,"Sai Gon"
       ,"Long An"
        ,"Ba Ria – Vung Tau"
      ,"Đong Thap"
      ,"An Giang"
       ,"Tien Giang"
      ,"Vinh Long"
      ,"Ben Tre"
       ,"Can Tho"
        ,"Kien Giang"
       ,"Tra Vinh"
        ,"Hau Giang"
       ,"Soc Trang"
      ,"Bac Lieu"
       ,"Ca Mau" };
    do
    {
        cout << "- Nhap ho va ten : ";
        cin.getline(sv.hoTen, 30);
        if (strlen(sv.hoTen) > 30 || chinhTen(sv.hoTen) == false || chinhSpaceCuaTen(sv.hoTen) == false)
        {
            system("cls");
            cout << "-> Nhap ten sai , vui long nhap lai , Ten co kich thuoc nho hon 30 va can phan phai format chuan ho ten !" << "\n";
            system("pause");
            system("cls");
        }
        if (kiemTraAsciiTen(sv.hoTen) == false)
        {
            system("cls");
            cout << "-> Nhap ten sai , vui long nhap lai ,Trong ten khong chua so tu 0 -> 9 !" << "\n";
            system("pause");
            system("cls");
        }
    } while (strlen(sv.hoTen) > 30 || chinhTen(sv.hoTen) == false || chinhSpaceCuaTen(sv.hoTen) == false || kiemTraAsciiTen(sv.hoTen) == false);
    do
    {
        cout << "- Nhap mssv : ";
        cin >> sv.mssv;
        if (sv.mssv < 1000 || sv.mssv>9999)
        {
            system("cls");
            cout << "-> Nhap mssv sai , vui long nhap lai , MSSV co 4 chu so !" << "\n";
            system("pause");
            system("cls");
        }
        if (kiemTraMaSinhVien(sv.mssv, n) == false)
        {

            system("cls");
            cout << "-> Ma so sinh vien tren ton tai , Vui long nhap ma so sinh vien khac !";
            system("pause");
            system("cls");
        }
    } while (sv.mssv < 1000 || sv.mssv>9999 || kiemTraMaSinhVien(sv.mssv, n) == false);
    do
    {
        cout << "- Nhap nam sinh:" << "\n";
        cout << " + Nhap ngay :";
        cin >> sv.ngay;
        cin.ignore();
        cout << " + Nhap thang : ";
        cin >> sv.thang;
        cin.ignore();
        cout << " + Nhap nam : ";
        cin >> sv.nam;
        if (kiemTraDate(sv.ngay, sv.thang, sv.nam) == false)
        {
            system("cls");
            cout << "-> Nhap ngay sinh sai , vui long nhap lai !" << "\n";
            system("pause");
            system("cls");

        }

    } while (kiemTraDate(sv.ngay, sv.thang, sv.nam) == false);
    cin.ignore();
    do
    {
        cout << "- Nhap gioi tinh :";
        getline(cin, sv.gioiTinh);
        if (chinhTenMonHoc(sv.gioiTinh) == false || sv.gioiTinh != "Nam" && sv.gioiTinh != "Nu")
        {
            system("cls");
            cout << "-> Nhap gioi tinh sai , vui long nhap lai , Gioi tinh chi co Nam va Nu !";
            system("pause");
            system("cls");
        }
    } while (chinhTenMonHoc(sv.gioiTinh) == false || sv.gioiTinh != "Nam" && sv.gioiTinh != "Nu");
    do
    {
        cout << "- Nhap que quan :";
        getline(cin, sv.queQuan);
        if (isMatch(sv.queQuan, dsTinhThanh, 64) == false)
        {
            system("cls");
            cout << "-> Nhap que quan sai , vui long nhap lai , Que quan la 63 tinh thanh trong Viet Nam !";
            system("pause");
            system("cls");
        }
    } while (isMatch(sv.queQuan, dsTinhThanh, 64) == false);
    do
    {
        cout << "- Nhap ten mon 1:";
        getline(cin, sv.tenMon1);
        cout << "- Nhap ten mon 2:";
        getline(cin, sv.tenMon2);
        cout << "- Nhap ten mon 3:";
        getline(cin, sv.tenMon3);
        if (chinhTenMonHoc(sv.tenMon1) == false || chinhTenMonHoc(sv.tenMon2) == false || chinhTenMonHoc(sv.tenMon3) == false)
        {
            system("cls");
            cout << "-> Nhap ten mon hoc sai , vui long nhap lai , Can format ten mon hoc !";
            system("pause");
            system("cls");
        }
    } while (chinhTenMonHoc(sv.tenMon1) == false || chinhTenMonHoc(sv.tenMon2) == false || chinhTenMonHoc(sv.tenMon3) == false);
    do
    {
        cout << "- Nhap diem mon " << sv.tenMon1 << ":";
        cin >> sv.diemMon1;
        cout << "- Nhap diem mon " << sv.tenMon2 << ":";
        cin >> sv.diemMon2;
        cout << "- Nhap diem mon " << sv.tenMon3 << ":";
        cin >> sv.diemMon3;
        if (sv.diemMon1 > 10 || sv.diemMon1 < 0 || sv.diemMon2>10 || sv.diemMon2 < 0 || sv.diemMon3>10 || sv.diemMon3 < 0)
        {
            system("cls");
            cout << "-> Nhap diem sai , vui long nhap lai, Diem gioi han tu 1->10 !" << "\n";
            system("pause");
            system("cls");
        }

    } while (sv.diemMon1 > 10 || sv.diemMon1 < 0 || sv.diemMon2>10 || sv.diemMon2 < 0 || sv.diemMon3>10 || sv.diemMon3 < 0);
    system("cls");
    sv.diemTb = (sv.diemMon1 + sv.diemMon2 + sv.diemMon3) / 3;
    ghiFile(sv, n);
    cin.ignore();


}

void nhapThongTinSinhVien(SINHVIEN ds[], int& n)
{
    cout << "                                         - NHAP SO LUONG SINH VIEN -" << "\n";
    cout << "- Nhap so luong sinh vien can them : ";
    cin >> n;
    ghiFileSoluong(n);
    system("cls");
    cin.ignore();
    int size = n;
    for (int i = 0; i < size; i++)
    {
        cout << "                                         - NHAP THONG TIN SINH VIEN -" << "\n";
        cout << "- Nhap thong tin sinh vien thu " << i + 1 << "\n";
        nhap(ds[i], n);
        system("cls");
        if (i + 1 != size)
        {
            ghiKiTuXuongDong();
        }

    }

}
void frame()
{
    cout << "+-----+" << "\t" << "+-----------------------+" << "\t" << "+----+" << "\t" << "+---------+" << "\t" << "+-----------+" << "\t" << "+---------------+" << "\t" << "+---------------+" << "\n";
}
void xuat(SINHVIEN sv)
{
    cout << "    " << setw(27) << left << sv.hoTen << "\t"<<" " << setw(5) << left << sv.mssv << "\t" << "    " << setw(1) << left << sv.gioiTinh << "\t" << "          " << setw(1) << left << sv.ngay << setw(1) << left << "/" << setw(1) << left << sv.thang << setw(1) << left << "/" << setw(1) << left << sv.nam << "\t" << "    " << setw(15) << left << sv.queQuan << "\t" << "\t" << setw(14) << left << sv.diemTb;

}
void xuatThongTinSinhVien(SINHVIEN ds[], int& n)
{

    int dem = 0;
    docFileSoLuong(n);
    if (n > 0)
    {
        cout << "                                        - DANH SACH THONG TIN SINH VIEN -" << "\n\n";
        frame();
        cout << setw(3) << left << "| STT |" << "\t" <<"|     "<< setw(10) << left << "Ho va ten         |" << setw(5) << left << "       |MSSV|" << "\t" << setw(1) << left << "|Gioi tinh|" << "\t"<<"|  "<< setw(8) << left << "Nam sinh"<<" |" << "\t" << "|    " << setw(15) << left << "Que quan   |"<< "\t" << setw(14) << left << "|Diem trung binh|" << "\n";
        docFile(ds, n);
        for (int i = 0; i < n; i++)
        {
            dem++;
            cout<<"   " << setw(4) << dem << "\t";
            xuat(ds[i]);
            cout << "\n\n";

        }
        frame();
    }
    else
    {
        cout << "-> Danh sach sinh vien tren hien tai dang rong , khong the xem !";
    }

}
void timKiem(SINHVIEN ds[], int& n)
{
    int tk;
    int check ;
    int index = 0 ;
    int dem1 = 0;
    int size;
    docFile(ds, n);
    docFileSoLuong(n);
    size = n;
    do
    {
        cout << "                                         - TIM KIEM THONG TIN SINH VIEN -" << "\n\n";
        cout << "- Nhap ma so sinh vien can tim kiem thong tin sinh vien:";
        cin >> tk;
        system("cls");
        int dem = 0;
        for (int i = 0; i < size; i++)
        {
            if (ds[i].mssv != tk)
            {
                check = 0;
                dem++;
            }
            else
            {
                index = i;
                check = 1;
                break;
            }
        }
        if (dem == size)
        {
            check = 0;
            cout << "-> Khong co sinh vien tren vui long nhap lai !";
            system("pause");
            system("cls");
        }
    }
    while (check == 0);
    dem1++;
    cout << "                                         - TIM KIEM THONG TIN SINH VIEN -" << "\n\n";
    frame();
    cout << setw(3) << left << "| STT |" << "\t" << "|     " << setw(10) << left << "Ho va ten         |" << setw(5) << left << "       |MSSV|" << "\t" << setw(1) << left << "|Gioi tinh|" << "\t" << "|  " << setw(8) << left << "Nam sinh" << " |" << "\t" << "|    " << setw(15) << left << "Que quan   |" << "\t" << setw(14) << left << "|Diem trung binh|" << "\n";
    cout << "   " << setw(4) << dem1 << "\t";
    xuat(ds[index]);
    cout << "\n";
    frame();
    system("pause");
    system("cls");


}


void themSinhVien(SINHVIEN ds[], int& n, SINHVIEN x)
{
    ds[n] = x;
    ++n;
    ghiFileSoluong(n);
}
void xoaSinhVien(SINHVIEN ds[], int& n, int vtXoa)
{
    for (int i = vtXoa + 1; i < n; i++)
    {
        ds[i - 1] = ds[i];
    }
    n--;
    ghiFileSoluong(n);
}
void hoanVi(SINHVIEN& x, SINHVIEN& y)
{
    SINHVIEN tam;
    tam = x;
    x = y;
    y = tam;
}
void sapXepTangDan(SINHVIEN ds[], int& n)
{
    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            if (ds[i].diemTb > ds[k].diemTb)
            {
                hoanVi(ds[i], ds[k]);
            }
        }
    }
}
void sapXepGiamDan(SINHVIEN ds[], int& n)
{
    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            if (ds[i].diemTb < ds[k].diemTb)
            {
                hoanVi(ds[i], ds[k]);
            }
        }
    }
}
void diemTbCaoNhat(SINHVIEN ds[], int& n)
{
    int dem = 0;
    int diemCaoNhat = ds[0].diemTb;
    cout << "                                     - SINH VIEN CO DIEM TRUNG BINH CAO NHAT -" << "\n\n";
    for (int i = 1; i < n; i++)
    {
        if (diemCaoNhat < ds[i].diemTb)
        {
            diemCaoNhat = ds[i].diemTb;
        }
    }
    frame();
    cout << setw(3) << left << "| STT |" << "\t" << "|     " << setw(10) << left << "Ho va ten         |" << setw(5) << left << "       |MSSV|" << "\t" << setw(1) << left << "|Gioi tinh|" << "\t" << "|  " << setw(8) << left << "Nam sinh" << " |" << "\t" << "|    " << setw(15) << left << "Que quan   |" << "\t" << setw(14) << left << "|Diem trung binh|" << "\n";
    for (int i = 0; i < n; i++)
    {
        if (diemCaoNhat == ds[i].diemTb)
        {
            dem++;
            cout << "   " << setw(4) << dem << "\t";
            xuat(ds[i]);
        }
        cout << "\n\n";
    }
    cout << "\n";
    frame();
}
void diemTbThapNhat(SINHVIEN ds[], int& n)
{
    int dem = 0;
    int diemThapNhat = ds[0].diemTb;
    cout << "                                     - SINH VIEN CO DIEM TRUNG BINH THAP NHAT -" << "\n\n";
    for (int i = 1; i < n; i++)
    {
        if (diemThapNhat > ds[i].diemTb)
        {
            diemThapNhat = ds[i].diemTb;
        }

    }
    frame();

    cout << setw(3) << left << "| STT |" << "\t" << "|     " << setw(10) << left << "Ho va ten         |" << setw(5) << left << "       |MSSV|" << "\t" << setw(1) << left << "|Gioi tinh|" << "\t" << "|  " << setw(8) << left << "Nam sinh" << " |" << "\t" << "|    " << setw(15) << left << "Que quan   |" << "\t" << setw(14) << left << "|Diem trung binh|" << "\n";
    for (int i = 0; i < n; i++)
    {
        if (diemThapNhat == ds[i].diemTb)
        {
            dem++;
            cout << "   " << setw(4) << dem << "\t";
            xuat(ds[i]);
        }
        cout << "\n\n";
    }
    cout << "\n";
    frame();
}
void sapXepChuCai(SINHVIEN ds[], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; i < n; i++)
        {
            int ketQua = strcmp(ds[i].hoTen, ds[k].hoTen);
            {
                if (ketQua >0)
                {
                    hoanVi(ds[i], ds[k]);
                }
            }
        }

    }
    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            swap(ds[i], ds[k]);
        }
    }

}
void xepLoaiHocLuc(SINHVIEN ds[], int& n)
{
    int demGioi = 0;
    int demKha = 0;
    int demTb = 0;
    SINHVIEN gioi[100];
    SINHVIEN kha[100];
    SINHVIEN trungBinh[100];
    int sizeGioi = 0;
    int sizeKha = 0;
    int sizeTb = 0;
    int kichThuoc;
    int a = 0;
    int b = 0;
    int c = 0;
    docFileSoLuong(n);
    kichThuoc = n;
    for (int i = 0; i < kichThuoc; i++)
    {
        if (ds[i].diemTb >= 8 && ds[i].diemTb <= 10)
        {
            gioi[sizeGioi] = ds[i];
            sizeGioi++;

        }
        else if (ds[i].diemTb >= 6 && ds[i].diemTb <= 7)
        {
            kha[sizeKha] = ds[i];
            sizeKha++;
        }
        else if (ds[i].diemTb <= 5)
        {
            trungBinh[sizeTb] = ds[i];
            sizeTb++;
        }
    }
    cout << "                          - XEP LOAI HOC LUC - " << "\n\n";
    if (a == 0)
    {
        if (sizeGioi > 0)
        {
            cout << "-> SINH VIEN TONG KET LOAI GIOI" << "\n\n";
            frame();
            cout << setw(3) << left << "| STT |" << "\t" << "|     " << setw(10) << left << "Ho va ten         |" << setw(5) << left << "       |MSSV|" << "\t" << setw(1) << left << "|Gioi tinh|" << "\t" << "|  " << setw(8) << left << "Nam sinh" << " |" << "\t" << "|    " << setw(15) << left << "Que quan   |" << "\t" << setw(14) << left << "|Diem trung binh|" << "\n";
            for (int i = 0; i < sizeGioi; i++)
            {
                demGioi++;
                cout << "   " << setw(4) << demGioi << "\t";
                xuat(gioi[i]);
                cout << "\n\n";
            }
            frame();

        }
        else
        {
            cout << "-> SINH VIEN TONG KET LOAI GIOI" << "\n\n";
            cout << "-> Khong co sinh vien nao dat loai gioi !" << "\n";

        }
    }
    cout << "\n\n";

    if (b == 0)
    {
        if (sizeKha > 0)
        {
            cout << "-> SINH VIEN TONG KET LOAI KHA" << "\n\n";
            frame();
            cout << setw(3) << left << "| STT |" << "\t" << "|     " << setw(10) << left << "Ho va ten         |" << setw(5) << left << "       |MSSV|" << "\t" << setw(1) << left << "|Gioi tinh|" << "\t" << "|  " << setw(8) << left << "Nam sinh" << " |" << "\t" << "|    " << setw(15) << left << "Que quan   |" << "\t" << setw(14) << left << "|Diem trung binh|" << "\n";
            for (int i = 0; i < sizeKha; i++)
            {
                demKha++;
                cout << "   " << setw(4) << demKha << "\t";
                xuat(kha[i]);
                cout << "\n";
            }
            frame();


        }
        else
        {
            cout << "-> SINH VIEN TONG KET LOAI KHA" << "\n\n";
            cout << "-> Khong co sinh vien nao dat loai kha !" << "\n";

        }
    }
    cout << "\n\n";
    if (c == 0)
    {
        if (sizeTb > 0)
        {
            cout << "-> SINH VIEN TONG KET LOAI TRUNG BINH" << "\n\n";
            frame();
            cout << setw(3) << left << "| STT |" << "\t" << "|     " << setw(10) << left << "Ho va ten         |" << setw(5) << left << "       |MSSV|" << "\t" << setw(1) << left << "|Gioi tinh|" << "\t" << "|  " << setw(8) << left << "Nam sinh" << " |" << "\t" << "|    " << setw(15) << left << "Que quan   |" << "\t" << setw(14) << left << "|Diem trung binh|" << "\n";
            for (int i = 0; i < sizeTb; i++)
            {
                demTb++;
                cout << "   " << setw(4) << demTb << "\t";
                xuat(trungBinh[i]);
                cout << "\n\n";
            }
            frame();

        }
        else
        {
            cout << "-> SINH VIEN TONG KET LOAI TRUNG BINH" << "\n\n";
            cout << "-> Khong co sinh vien nao dat loai trung binh !" << "\n";
        }
    }

}
void capNhatSinhVien(SINHVIEN ds[], int& n)
{
    cout << "                                      - CAP NHAT DANH SACH SINH VIEN - " << "\n\n";
    xoaToanBoFile();
    nhapThongTinSinhVien(ds, n);
    ghiFileSoluong(n);
    cout << "\n";
    cout << "Da cap nhat sinh vien!";
    system("pause");
    system("cls");

}
void MENU(SINHVIEN ds[], PASSWORD dsPW[], int& n, int& soLuong)
{
    int chon;
    string tenDangNhap;
    int matKhauDangNhap;
    int phu;
    int cLS = 0 ;
    while (true)
    {
        system("cls");
        do
        {
            cout << "                                   -CHAO MUNG DEN VOI PHAN MEM QUAN LY SINH VIEN- " << "\n\n";
            cout << "[1] DANG KY" << "\n";
            cout << "[2] DANG NHAP" << "\n";
            cout << "[0] THOAT" << "\n";
            cout << "- Nhap lua chon cua ban :";
            cin >> chon;
            system("cls");

            if ( chon > 2)
            {
                cout << "-> Khong co hang muc tren , vui long nhap lai !" << "\n";
                system("pause");
                system("cls");

            }
        } while (chon > 2);
        if (chon == 1)
        {
            PASSWORD pW;
            nhapDsPassWord(pW, soLuong);
        }
        else if (chon == 2)
        {

            do
            {
                cin.ignore();
                cout << "    - DANG NHAP - " << "\n";
                cout << "- Nhap ten dang nhap :";
                getline(cin, tenDangNhap);
                cout << "- Nhap mat khau dang nhap:";
                cin >> matKhauDangNhap;
                system("cls");
                if (tenDangNhap.length() > 50 || matKhauDangNhap < 1000 || matKhauDangNhap>9999)
                {
                    cout << "                          DANG NHAP TAI KHOAN KHONG THANH CONG , VUI LONG NHAP LAI !" << "\n";
                    system("pause");
                    system("cls");
                }
            } while (tenDangNhap.length() > 50 || matKhauDangNhap < 1000 || matKhauDangNhap>9999);
            docFileSoLuongPw(soLuong);
            docPassWordTuFile(dsPW, soLuong);
            for (int i = 0; i < soLuong; i++)
            {
                if (dsPW[i].tenDangKy == tenDangNhap && dsPW[i].matKhauDangKy == matKhauDangNhap)
                {
                    phu = 1;
                    break;
                }
                else
                {
                    phu = 0;
                }


            }

            system("cls");
            if (phu == 1)
            {
                system("cls");
                cout << "                                         DANG NHAP THANH CONG !" << "\n";
                system("pause");
                system("cls");
                int luachon;
                int luaChon1;
                while (true)
                {
                    do
                    {
                        cout << "- Ban dang nhap voi tu cach la:" << "\n";
                        cout << "   -> [1] Giao Vien " << "\n";
                        cout << "   -> [2] Sinh Vien" << "\n";
                        cout << "   -> [0] Thoat" << "\n";
                        cout << "- Nhap lua chon cua ban:";
                        cin >> luaChon1;
                        system("cls");
                        if (luaChon1 < 0 || luaChon1>2)
                        {
                            cout << "Khong co doi tuong tren , Vui long nhap lai !";
                            system("pause");
                            system("cls");
                        }

                    } while (luaChon1 < 0 || luaChon1>2);
                    if (luaChon1 == 1)
                    {
                        cout << "                                  - BAN DA CHON VOI TU CACH LA MOT GIAO VIEN - " << "\n";
                        system("pause");
                        system("cls");
                        while (true)
                        {

                            do
                            {
                                cout << "                                 --------------------------------------" << "\n";
                                cout << "                                 || -CHUONG TRINH QUAN LY SINH VIEN- ||" << "\n";
                                cout << "                                 --------------------------------------" << "\n";
                                cout << "                     *************************************************************" << "\n";
                                cout << "                     *                       ------                              *" << "\n";
                                cout << "                     *                       |MENU|                              *" << "\n";
                                cout << "                     *                       ------                              *" << "\n";
                                cout << "                     *    [1]  NHAP THONG TIN SINH VIEN                          *" << "\n";
                                cout << "                     *    [2]  XUAT THONG TIN SINH VIEN                          *" << "\n";
                                cout << "                     *    [3]  TIM KIEM SINH VIEN                                *" << "\n";
                                cout << "                     *    [4]  THEM THONG TIN SINH VIEN                          *" << "\n";
                                cout << "                     *    [5]  XOA THONG TIN SINH VIEN                           *" << "\n";
                                cout << "                     *    [6]  SAP XEP DANH SACH SINH VIEN TANG DAN              *" << "\n";
                                cout << "                     *    [7]  SAP XEP DANH SACH SINH VIEN GIAM DAN              *" << "\n";
                                cout << "                     *    [8]  PHAN LOAI SINH VIEN CO DIEM TRUNG BINH CAO NHAT   *" << "\n";
                                cout << "                     *    [9]  PHAN LOAI SINH VIEN CO DIEM TRUNG BINH THAP NHAT  *" << "\n";
                                cout << "                     *    [10] XEP LOAI HOC LUC SINH VIEN                        *" << "\n";
                                cout << "                     *    [11] SAP XEP THEO CHU CAI                              *" << "\n";
                                cout << "                     *    [12] CAP NHAT SINH VIEN                                *" << "\n";
                                cout << "                     *    [0]  THOAT                                             *" << "\n";
                                cout << "                     *************************************************************" << "\n";
                                cout << "\n";
                                cout << "- VUI LONG NHAP LUA CHON CUA BAN: ";
                                cin >> luachon;
                                if (luachon < 0 || luachon>13)
                                {

                                    cout << "-> KHONG CO CHUC NANG TREN . VUI LONG NHAP LAI! " << "\n";
                                    system("pause");
                                    system("cls");

                                }

                            } while (luachon < 0 || luachon>13);
                            system("cls");
                            if (luachon == 1)
                            {
                                nhapThongTinSinhVien(ds, n);
                                cout << "-> Nhap thanh cong !";
                                system("pause");
                                system("cls");
                            }
                            else if (luachon == 2)
                            {
                                xuatThongTinSinhVien(ds, n);
                                system("pause");
                                system("cls");
                            }
                            else if (luachon == 3)
                            {
                                timKiem(ds, n);
                            }
                            else if (luachon == 4)
                            {
                                SINHVIEN x;
                                cout << "                                  - THEM SINH VIEN -" << "\n";
                                cin.ignore();
                                nhap(x, n);
                                themSinhVien(ds, n, x);
                                xoaToanBoFile();
                                ghiFileChucNang(ds, n);
                                cout << "-> Da them sinh vien !";
                                system("pause");
                                system("cls");

                            }
                            else if (luachon == 5)
                            {
                                int vtXoa, x;
                                cout << "                                  - XOA SINH VIEN -" << "\n";
                                cout << "- Nhap STT can xoa :";
                                cin >> x;
                                system("cls");
                                vtXoa = x - 1;
                                xoaSinhVien(ds, n, vtXoa);
                                cout << "-> Da xoa sinh vien !";
                                system("pause");
                                system("cls");
                                xoaToanBoFile();
                                ghiFileChucNang(ds, n);
                            }
                            else if (luachon == 6)
                            {

                                cout << "                          - SAP XEP SINH VIEN THEO THU TU TANG DAN - " << "\n\n";
                                sapXepTangDan(ds, n);
                                int dem = 0;
                                frame();
                                cout << setw(3) << left << "| STT |" << "\t" << "|     " << setw(10) << left << "Ho va ten         |" << setw(5) << left << "       |MSSV|" << "\t" << setw(1) << left << "|Gioi tinh|" << "\t" << "|  " << setw(8) << left << "Nam sinh" << " |" << "\t" << "|    " << setw(15) << left << "Que quan   |" << "\t" << setw(14) << left << "|Diem trung binh|" << "\n";
                                for (int i = 0; i < n; i++)
                                {
                                    dem++;
                                    cout << "   " << setw(4) << dem << "\t";
                                    xuat(ds[i]);
                                    cout << "\n\n";

                                }
                                frame();
                                system("pause");
                                system("cls");

                            }
                            else if (luachon == 7)
                            {
                                cout << "                          - SAP XEP SINH VIEN THEO THU TU GIAM DAN - " << "\n\n";
                                sapXepGiamDan(ds, n);
                                int dem = 0;
                                frame();
                                cout << setw(3) << left << "| STT |" << "\t" << "|     " << setw(10) << left << "Ho va ten         |" << setw(5) << left << "       |MSSV|" << "\t" << setw(1) << left << "|Gioi tinh|" << "\t" << "|  " << setw(8) << left << "Nam sinh" << " |" << "\t" << "|    " << setw(15) << left << "Que quan   |" << "\t" << setw(14) << left << "|Diem trung binh|" << "\n";
                                for (int i = 0; i < n; i++)
                                {
                                    dem++;
                                    cout << "   " << setw(4) << dem << "\t";
                                    xuat(ds[i]);
                                    cout << "\n\n";

                                }
                                frame();
                                system("pause");
                                system("cls");

                            }
                            else if (luachon == 8)
                            {
                                diemTbCaoNhat(ds, n);
                                system("pause");
                                system("cls");

                            }
                            else if (luachon == 9)
                            {
                                diemTbThapNhat(ds, n);
                                system("pause");
                                system("cls");

                            }
                            else if (luachon == 10)
                            {
                                xepLoaiHocLuc(ds, n);
                                system("pause");
                                system("cls");

                            }
                            else if (luachon == 11)
                            {
                                cout << "                                   - SAP XEP THEO CHU CAI - " << "\n\n";
                                cout << "-> Da sap ten sinh vien theo chuan Alphabet !";
                                xoaToanBoFile();
                                sapXepChuCai(ds, n);
                                ghiFileChucNang(ds, n);

                                system("pause");
                                system("cls");

                            }
                            else if (luachon == 12)
                            {
                                capNhatSinhVien(ds, n);
                            }

                            else if (luachon == 0)
                            {
                                cout << "                                  - QUAY TRO LAI PHAN CHON DOI TUONG -" << "\n";
                                system("pause");
                                system("cls");
                                break;
                            }
                        }
                    }
                    else if (luaChon1 == 2)
                    {
                        cout << "                                  - BAN DA CHON VOI TU CACH LA MOT SINH VIEN - " << "\n";
                        system("pause");
                        system("cls");
                        while (true)
                        {
                            do
                            {
                                system("cls");
                                cout << "                                 --------------------------------------" << "\n";
                                cout << "                                 || -CHUONG TRINH QUAN LY SINH VIEN- ||" << "\n";
                                cout << "                                 --------------------------------------" << "\n";
                                cout << "                     *************************************************************" << "\n";
                                cout << "                     *                       ------                              *" << "\n";
                                cout << "                     *                       |MENU|                              *" << "\n";
                                cout << "                     *                       ------                              *" << "\n";
                                cout << "                     *    [1]  XUAT THONG TIN SINH VIEN                          *" << "\n";
                                cout << "                     *    [2]  TIM KIEM SINH VIEN                                *" << "\n";
                                cout << "                     *    [3]  SAP XEP DANH SACH SINH VIEN TANG DAN              *" << "\n";
                                cout << "                     *    [4]  SAP XEP DANH SACH SINH VIEN GIAM DAN              *" << "\n";
                                cout << "                     *    [5]  PHAN LOAI SINH VIEN CO DIEM TRUNG BINH CAO NHAT   *" << "\n";
                                cout << "                     *    [6]  PHAN LOAI SINH VIEN CO DIEM TRUNG BINH THAP NHAT  *" << "\n";
                                cout << "                     *    [7]  SAP XEP THEO CHU CAI                              *" << "\n";
                                cout << "                     *    [0]  THOAT                                             *" << "\n";
                                cout << "                     *************************************************************" << "\n";
                                cout << "\n";
                                cout << "- VUI LONG NHAP LUA CHON CUA BAN: ";
                                cin >> luachon;
                                if (luachon < 0 || luachon>7)
                                {
                                    cout << "-> KHONG CO CHUC NANG TREN . VUI LONG NHAP LAI! " << "\n";
                                    system("pause");
                                    system("cls");
                                }
                            } while (luachon < 0 || luachon>7);
                            system("cls");
                            if (luachon == 1)
                            {
                                xuatThongTinSinhVien(ds, n);
                                system("pause");
                                system("cls");
                            }
                            else if (luachon == 2)
                            {
                                timKiem(ds, n);
                            }

                            else if (luachon == 3)
                            {

                                cout << "                          - SAP XEP SINH VIEN THEO THU TU TANG DAN - " << "\n\n";
                                sapXepTangDan(ds, n);
                                int dem = 0;
                                frame();
                                cout << setw(3) << left << "| STT |" << "\t" << "|     " << setw(10) << left << "Ho va ten         |" << setw(5) << left << "       |MSSV|" << "\t" << setw(1) << left << "|Gioi tinh|" << "\t" << "|  " << setw(8) << left << "Nam sinh" << " |" << "\t" << "|    " << setw(15) << left << "Que quan   |" << "\t" << setw(14) << left << "|Diem trung binh|" << "\n";
                                for (int i = 0; i < n; i++)
                                {
                                    dem++;
                                    cout << "   " << setw(4) << dem << "\t";
                                    xuat(ds[i]);
                                    cout << "\n\n";

                                }
                                frame();
                                system("pause");
                                system("cls");

                            }
                            else if (luachon == 4)
                            {
                                cout << "                          - SAP XEP SINH VIEN THEO THU TU GIAM DAN - " << "\n\n";
                                sapXepGiamDan(ds, n);
                                int dem = 0;
                                frame();
                                cout << setw(3) << left << "| STT |" << "\t" << "|     " << setw(10) << left << "Ho va ten         |" << setw(5) << left << "       |MSSV|" << "\t" << setw(1) << left << "|Gioi tinh|" << "\t" << "|  " << setw(8) << left << "Nam sinh" << " |" << "\t" << "|    " << setw(15) << left << "Que quan   |" << "\t" << setw(14) << left << "|Diem trung binh|" << "\n";
                                for (int i = 0; i < n; i++)
                                {
                                    dem++;
                                    cout << "   " << setw(4) << dem << "\t";
                                    xuat(ds[i]);
                                    cout << "\n\n";

                                }
                                frame();
                                system("pause");
                                system("cls");
                            }
                            else if (luachon == 5)
                            {
                                diemTbCaoNhat(ds, n);
                                system("pause");
                            }
                            else if (luachon == 6)
                            {
                                diemTbThapNhat(ds, n);
                                system("pause");
                            }

                            else if (luachon == 7)
                            {
                                cout << "                                   - SAP XEP THEO CHU CAI - " << "\n\n";
                                cout << "-> Da sap ten sinh vien theo chuan Alphabet !";
                                xoaToanBoFile();
                                sapXepChuCai(ds, n);
                                ghiFileChucNang(ds, n);

                                system("pause");
                            }
                            else if (luachon == 0)
                            {
                                cout << "                                   - QUAY TRO LAI PHAN CHON DOI TUONG -" << "\n";
                                system("pause");
                                system("cls");
                                break;
                            }
                        }
                    }
                    else if (luaChon1 == 0)
                    {

                        cout << "                                           - QUAY TRO LAI TRANG CHU - " << "\n";
                        system("pause");
                        system("cls");
                        break;


                    }
                }

            }
            else if (phu == 0)
            {
                cout << "                           * TAI KHOAN TREN HIEN KHONG CO . VUI LONG DANG NHAP LAI ! *";
                system("pause");
            }
        }
        else
        {
            cout << "                                - CAM ON DA TRUY CAP PHAN MEM QUAN LY SINH VIEN -" << "\n";
            system("pause");
            break;
        }
    }
}
int main()
{
    SINHVIEN ds[100];
    PASSWORD dsPw[100];
    int n, soLuong = 0;
    system("cls");
    MENU(ds, dsPw, n, soLuong);
    return 0;
}
