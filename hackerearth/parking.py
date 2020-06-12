
class ParkedVehicle:

    def __init__(self , vehicleSeq , fourWheeler , parkedFor, valetParking  , lot_number):

        self.vechicleSeq = vehicleSeq
        self.fourWheeler = fourWheeler
        self.parkedFor = parkedFor
        self.valetParking = valetParking
        self.parkedStatus = "Parked"
        self.lot_number = lot_number


class ParkingLot:

    def __init__(self , parkd_vehicle):

        self.parkd_vehicle = parkd_vehicle
    
    def display(self):
        print(self.parkd_vehicle)

    def updateParkingStatus(self  , lot_number):

        for item in self.parkd_vehicle.values():
            if(item.lot_number == lot_number):
                item.parkedStatus = "Cleared"
                return (lot_number , item)
     
    def getParkingCharkges(self , lot_number):

        for item in self.parkd_vehicle.values():
            if(item.lot_number == lot_number):
                hour = item.parkedFor
                if(item.fourWheeler == "Yes"):
                    charges = hour * 50
                else:
                    charges = hour * 30

                if(item.valetParking == "Yes"):
                    charges += 10
                return charges
        return None
                


parked_vehicle_dict = {}
for _ in range(int(input())):

    vehicleSeq = int(input())
    fourWheeler = input()
    parkedFor = float(input())
    valetParking = input()
    lot_number = input()

    parked_vehicle_dict[lot_number] = ParkedVehicle(vehicleSeq , fourWheeler , parkedFor , valetParking , lot_number)

lot_number = input()
parking_lot_obj = ParkingLot(parked_vehicle_dict)
ans = parking_lot_obj.updateParkingStatus(lot_number)
print(ans[0] , ans[1].parkedStatus)
print(parking_lot_obj.getParkingCharkges(lot_number))





