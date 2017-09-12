import serial;
import sys;
from pubnub import Pubnub;
pubnub=Pubnub(publish_key='pub-c-91cc8164-31a3-4284-a48d-c48ca710697f',subscribe_key='sub-c-314b1b68-61fc-11e6-8de8-02ee2ddab7fe');
channel='robochannel'
ser=serial.Serial('/dev/ttyACM0',9600);
base=0
sa0=0

def _callback(m,channel):
 base0=m['revBase0']
 sa0=m['revSa0']
 base1=m['revBase1']
 sa1=m['revSa1']
 base2=m['revBase2']
 print base0
 print sa0
 print base1
 print sa1
 print base2
 ser.write(base0)
 ser.write(sa0)
 ser.write(base1)
 ser.write(sa1)
 ser.write(base2)
 
def _error(message):
    print(message)

pubnub.subscribe(channel, callback=_callback, error=_error)