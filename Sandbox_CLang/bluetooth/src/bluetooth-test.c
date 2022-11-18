#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/sdp.h>
#include <bluetooth/sdp_lib.h>
/*
 * 00001200-0000-1000-8000-00805f9b34fb PnP Information
0000111f-0000-1000-8000-00805f9b34fb Handsfree Audio Gateway
0000112f-0000-1000-8000-00805f9b34fb Phonebook Access (PBAP) - PSE
0000110a-0000-1000-8000-00805f9b34fb Audio Source
0000110c-0000-1000-8000-00805f9b34fb Remote Control Target
00001132-0000-1000-8000-00805f9b34fb Message Access Server
00000000-deca-fade-deca-deafdecacafe Proprietary
 */
void list_bluetooth_devices()
{
    inquiry_info *ii = NULL;
    int max_rsp, num_rsp;
    int dev_id, sock, len, flags;
    int i;
    char addr[19] = { 0 };
    char name[248] = { 0 };
    //char* device_address = "20:09:17:CD:86:23";
    //dev_id = hci_devid(device_address);
    //printf("The device id is %d\n", dev_id);
    dev_id = hci_get_route("20:09:17:CD:86:23");
    sock = hci_open_dev( dev_id );
    printf("The device id is %d\n", dev_id);
    if (dev_id < 0 || sock < 0) {
        perror("opening socket");
        exit(1);
    } else {
        printf("Successfully opened the Bluetooth socket!\n");
    }

    len  = 8;
    max_rsp = 255;
    flags = IREQ_CACHE_FLUSH;
    ii = (inquiry_info*)malloc(max_rsp * sizeof(inquiry_info));

    num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &ii, flags);
    if( num_rsp < 0 ) perror("hci_inquiry");
    else printf("The inquiry has finished successfully!\n");
    printf("The list of the bluetooth devices available:\n");
    for (i = 0; i < num_rsp; i++) {
        ba2str(&(ii+i)->bdaddr, addr);
        memset(name, 0, sizeof(name));
        if (hci_read_remote_name(sock, &(ii+i)->bdaddr, sizeof(name), name, 0) < 0)
            strcpy(name, "[unknown]");
        printf("%s  %s\n", addr, name);
    }

    free( ii );
    close( sock );
}