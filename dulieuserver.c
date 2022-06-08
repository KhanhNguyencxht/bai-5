#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	char light;
	char fan;
	char motor;
}smartHome_t;

char data[] = "HTTP1.1 200 OK\r\n{\r\n\t\"light\" : \"on\",\r\n\t\"fan\" : \"off\",\r\n\t\"motor\" : \"off\"\r\n}";

void light_(smartHome_t* nha) {
	int x = 0;
	int i = 0;
	int vtrion = 0;
	char* giatri = 0;
	char light[3] = { 0 };
	while (data[x] != 0) {
		x++;
		if (data[x] == 'l')
		{
			giatri = &data[x];  //tim dia chi bat dau light
		}
	}
//.......................................................
	while (giatri[i] != 'o') {
		i++;
			vtrion++;			//dem so ky tu từ light đến n
		}
//.......................................................
	memcpy(light, (giatri+vtrion), 2);	// coppy trang thai on để gán trạng thái tắt bật thiết bị

	if (light[1] == 'n') {
		nha->light = 1;
		printf("trang thai light: %d: \r\n", nha->light);  // trạng thái on thì bật thiết bị lên 1
	}
	else {
		nha->light = 0;
		printf("trang thai light: %d \r\n", nha->light);	// trạng thái off thì tắt thiết bị về 0
	}
	
}
////////////////////////////////////////////////////////////////////////////////////////////
void fan(smartHome_t* nha) {
	int x = 0;
	int i = 0;
	int vtrion = 0;
	char* giatri = 0;
	char fan[3] = { 0 };
	while (data[x] != 0) {
		x++;
		if (data[x] == 'f')
		{
			giatri = &data[x];  //tim dia chi bat dau light
		}
	}
	//.......................................................
	while (giatri[i] != 'o') {
		i++;
		vtrion++;			//dem so ky tu từ light đến n
	}
	//.......................................................
	//vton = *(giatri + vtrion);  // tim vị trí n để gán trạng thái tắt bật thiết bị
	memcpy(fan, (giatri + vtrion), 2);
	if (fan[1] == 'n') {
		nha->light = 1;
		printf("trang thai fan: %d \r\n", nha->light);  // trạng thái on thì bật thiết bị lên 1
	}
	else {
		nha->light = 0;
		printf("trang thai fan: %d \r\n", nha->light);	// trạng thái off thì tắt thiết bị về 0
	}
}
//////////////////////////////////////////////////////////////////////
void motor(smartHome_t* nha) {
	int x = 0;
	int i = 0;
	int vtrion = 0;
	char* giatri = 0;
	char motor[3] = { 0 };
	while (data[x] != 0) {
		x++;
		if (data[x] == 'm')
		{
			giatri = &data[x];  //tim dia chi bat dau light
		}
	}
	//.......................................................
	while (giatri[i] != 'o') {
		i++;
		vtrion++;			//dem so ky tu từ light đến n
	}
	//.......................................................
	memcpy(motor, (giatri + vtrion), 2);	// coppy trang thai on để gán trạng thái tắt bật thiết bị

	if (motor[1] == 'n') {
		nha->light = 1;
		printf("trang thai motor: %d: \r\n", nha->light);  // trạng thái on thì bật thiết bị lên 1
	}
	else {
		nha->light = 0;
		printf("trang thai motor: %d \r\n", nha->light);	// trạng thái off thì tắt thiết bị về 0
	}

}


void main() {
	smartHome_t nha;
	light_(&nha);
	fan(&nha);
	motor(&nha);
}