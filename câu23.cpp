#include<iostream>
#include <iomanip>
#include <vector>
using namespace std;
struct sach{
    string masach;
    string tensach;
    string tacgia;
    int soluong;
};
struct nodesach{
    sach data;
    nodesach *next;
};
class listsach{
    private:
    nodesach *head;
    nodesach *tail;
    int size;
    public:
    nodesach* createnodesach(sach s);
    listsach();
    bool isempty();
    void indssach();
    void themsachdauds(sach s);
    void themsachcuoids(sach s);
    void themsachbatkids(sach s, int pos);
    int soluongsach();
};
int listsach::soluongsach(){
    int size=0;
    for(nodesach *p=head; p!=NULL; p=p->next){
        size++;
    }
    return size;
}
listsach::listsach(){
    head=tail=NULL;
    size=0;
}
bool listsach::isempty(){
    return head==NULL;
}
nodesach *listsach::createnodesach(sach s){
    nodesach *p=new nodesach();
    p->data=s;
    p->next=NULL;
    return p;
}
void listsach::themsachdauds(sach s){
    nodesach *p=createnodesach(s);
    if(head==NULL){
        head=tail=p;
    }else{
        p->next=head;
        head=p;
    }
    size++;
}
void listsach::themsachcuoids(sach s){
    nodesach *p=createnodesach(s);
    if(head==NULL){
        head=tail=p;
    }else{
        tail->next=p;
        tail=p;
    }
    size++;
}
void listsach::themsachbatkids(sach s, int pos){
    int size=soluongsach();
    if(pos <=0 || pos > size+1){
        cout<<"vi tri chen khong hop le!"<<endl;
        return;
    }
    nodesach *p=createnodesach(s);
    nodesach *a=head;
    if(pos==1){
        themsachdauds(s);
        return;
    }else if(pos==size+1){
        themsachcuoids(s);
        return;
    }
    for(int i=1; i<pos -1; i++){
        a=a->next;
    }
    p->next=a->next;
    a->next=p;
    size++;
}
void listsach::indssach(){
    if (isempty()) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    cout << "\n===== DANH SACH SACH =====" << endl;
    cout << left
         << setw(10) << "STT"
         << setw(15) << "Ma sach"
         << setw(30) << "Ten sach"
         << setw(25) << "Tac gia"
         << setw(10) << "So luong" << endl;
    int i = 1;
    for (nodesach *p = head; p != NULL; p = p->next) {
        cout << left
             << setw(10) << i++
             << setw(15) << p->data.masach
             << setw(30) << p->data.tensach
             << setw(25) << p->data.tacgia
             << setw(10) << p->data.soluong
             << endl;
    }
}
struct muontra {
    string madg;
    string masach;
    string tensach;
    string trangthai;
};
class listMuontra {
   private:
    vector<muontra> dsmt;

   public:
    void muonSach(string madg, nodesach* a);
    void traSach(string madg, nodesach* a);
    bool kiemtraSachDangMuonID(string masach);
};
void listMuontra::muonSach(string madg, nodesach* a) {
    if (a == NULL) {
        cout << "Khong ton tai sach voi ma vua nhap!" << endl;
        return;
    }
    if (a->data.soluong <= 0) {
        cout << "Da het sach.";
        return;
    }
    a->data.soluong--;
    muontra mt;
    mt.madg = madg;
    mt.masach = a->data.masach;
    mt.tensach = a->data.tensach;
    mt.trangthai = "Dang muon";
    dsmt.push_back(mt);
    cout << "Ban da muon thanh cong sach :" << a->data.tensach;
}
void listMuontra::traSach(string madg, nodesach* a) {
    for (auto& x : dsmt) {
        if (x.madg == madg && x.masach == a->data.masach && x.trangthai == "Dang muon") {
            x.trangthai = "Da tra";
            a->data.soluong++;
            cout << "Tra sach thanh cong.";
            return;
        }
    }
    cout << "Khong tim thay sach da muon";
}
bool listMuontra ::kiemtraSachDangMuonID(string masach){
    for (auto& mt:dsmt){
        if(mt.masach == masach && mt.trangthai== "Dang muon"){
            return true ;
        }
    }
    return false;
}   
int main(){

};




