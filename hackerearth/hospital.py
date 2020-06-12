
class Hospital:

    def __init__(self , doctorDB):
        self.doctorDB = doctorDB;

    def searchByDoctorName(self , name):
        
        doctorList = []
        for i in doctorDB.values():
            # print(i.doctorName , name)
            if(i.doctorName == name):
                doctorList.append(i)
        return doctorList
        
    def searchByFee(self , spec):
        sum = 0
        for i in doctorDB.values():
            print(i.specialisation , spec)
            if(i.specialisation == spec):
                print(i.fee)
                sum += i.fee 
        return sum


class Doctor:

    def __init__(self , doctorId , doctorName , specialisation , fee):
        self.doctorId = doctorId
        self.doctorName  = doctorName
        self.specialisation = specialisation
        self.fee = fee 
    def display(self):
        print(self.doctorName)

doctorDB = {}
for _ in range(int(input())):
    id = int(input())
    name = input().lower()
    spec = input().lower()
    fee  = int(input())

    doctorDB[id]  = Doctor(id , name , spec , fee)

hobj = Hospital(doctorDB)
l = (hobj.searchByDoctorName(input().lower()))
if not l:
    print("sdf")
fee = (hobj.searchByFee(input().lower()))
if not fee:
    print("sdfdsdfs")
else:
    print(fee)

    
