/* This header is shared between the firmware and the host software. It
 * defines the USB vid/pid numbers
 */

#ifndef __USB_ID_H_INCLUDED__
#define __USB_ID_H_INCLUDED__

#define USB_CFG_VENDOR_NAME     'o', 'b', 'd', 'e', 'v', '.', 'a', 't'
#define USB_CFG_VENDOR_NAME_LEN 8
/* These two values define the vendor name returned by the USB device. The name
 * must be given as a list of characters under single quotes. The characters
 * are interpreted as Unicode (UTF-16) entities.
 * If you don't want a vendor name string, undefine these macros.
 * ALWAYS define a vendor name containing your Internet domain name if you use
 * obdev's free shared VID/PID pair. See the file USBID-License.txt for
 * details.
 */

#define USB_CFG_DEVICE_NAME     'L', 'E', 'D', 'C', 'o', 'n', 't', 'r', 'o', 'l'
#define USB_CFG_DEVICE_NAME_LEN 10
/* Same as above for the device name. If you don't want a device name, undefine
 * the macros. See the file USBID-License.txt before you assign a name if you
 * use a shared VID/PID.
 */

#define  USB_CFG_VENDOR_ID       0xc0, 0x16
/* USB vendor ID for the device, low byte first. If you have registered your
 * own Vendor ID, define it here. Otherwise you use one of obdev's free shared
 * VID/PID pairs. Be sure to read USBID-License.txt for rules!
 */
#define  USB_CFG_DEVICE_ID       0xdc, 0x05
/* This is the ID of the product, low byte first. It is interpreted in the
 * scope of the vendor ID. If you have registered your own VID with usb.org
 * or if you have licensed a PID from somebody else, define it here. Otherwise
 * you use obdev's free shared VID/PID pair. Be sure to read the rules in
 * USBID-License.txt!
 */

 /* === Requests === */

#define RFMUSB_RQ_ECHO          0x00
/* Request that the device sends back wValue and wIndex. This is used with
 * random data to test the reliability of the communication.
 */

//put data into the rfm12 transmit buffer
#define RFMUSB_RQ_RFM12_PUT			0x01

//poll for rfm12 received data
#define RFMUSB_RQ_RFM12_GET			0x02

#define RFMUSB_RQ_CTRL	0x04

//poll for notifications
#define RFMUSB_RQ_GETNOTIFICATION	0x03

/* reset device - i.e. to enter the bootloader */
#define RFMUSB_CTRL_RESET 0x00
#define RFMUSB_CTRL_SET_RATE 0x02
#define RFMUSB_CTRL_SET_BW 0x03
#define RFMUSB_CTRL_SET_RAWTX 0x04
#endif
