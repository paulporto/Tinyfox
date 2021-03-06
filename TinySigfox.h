/*
Derechos Reservados "Teca" 2020, autor Marco A. Caballero Rev.1.5
Contibutor: Paul Portocarrero Hernandez
*/
#ifndef TINYSIGFOX_H
#define TINYSIGFOX_H
#include <Arduino.h>
#define buffersize 40

template <class M,class DBG > class Tiny
{
  public:
    //Tiny();
    //Tiny(bool _dbg);
   Tiny (M *modulo,DBG *dbg, uint8_t _rst_ws=12,bool _dbgMode=false );
    void EnableDebug(bool _dbgMode);
    void begin(uint16_t _baudio=9600);
    String command(String _cmd);
    String command2(String _cmd);
    String ID();
    String PAC();
    uint16_t TEMP();
    uint16_t VOLT();
    void RST();
    String SLEEP();
    String SEND(uint32_t _dataint);
    String SEND(String _datastr);
    String SEND_RCV(uint32_t _dataint_rcv);
    String SEND_RCV(String _datastr_rcv);
    M * Modulo ;

  private:
    //M * Modulo ;
    DBG * Debug ;
    #define baud_ws 9600
    uint8_t pin_rst_wisol=12;
    String ATS = "AT$";
    String ENV = "env:> ";
    String RCV = "<rec: ";
    String GI = "GI?";
    String RC = "RC";
   
    char caracter = 0x00;
    char cadena_cad[buffersize]; //= ""; esto causa un error al compilar para esp8266, mejor dejarlo vacio
    uint8_t i;
    bool dbgMode = false;
    uint8_t rst_ws;
    uint32_t dato;
    uint16_t baudio;
    String cmd;
    uint32_t dataint;
    String datastr;
    uint32_t dataint_rcv;
    String datastr_rcv;
};

#endif