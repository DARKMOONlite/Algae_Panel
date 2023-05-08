#include <EEPROM_Manager.h>

EEPROM_Variable::EEPROM_Variable(int _Variable,uint8_t _EE_Loc,EEPROM_Manager* _Manager)
    :default_var(_Variable)
{
    var = _Variable;

    if(_Manager!=NULL){ // add this EEPROM variable to the EEPROM manager
        if(_Manager->Add(this,_EE_Loc)){ // if EE_Loc is within memory constrains of arduino & not already used by another variable
            EEPROM_LOC = _EE_Loc;
        }
    }

}
void EEPROM_Variable::Store(){
    if(EEPROM_LOC<0){
    return;
    }
    for(size_t i =0;i<sizeof(int);i++){
        EEPROM.update(EEPROM_LOC*sizeof(int)+i,*((uint8_t*)(&var)+i));
    }
}

int EEPROM_Variable::Retrieve(){
    if(EEPROM_LOC<0){
        return(-1);
    }
    var = 0;
    for(size_t i=0;i<sizeof(int);i++){
        var |= ((int)EEPROM.read(EEPROM_LOC*sizeof(int)+i)<<8*i); //! check if this is little or big endian
    
    }  
    return(var); 
}

void EEPROM_Variable::Reset(){
    var = default_var;
}


    EEPROM_Manager::EEPROM_Manager(){

    }


    void EEPROM_Manager::Store(){
        for(size_t i=0; i < EEPROM_Vector.size();i++){
            EEPROM_Vector.at(i)->Store();
        }
    }

    void EEPROM_Manager::Retrieve(){
        for(size_t i=0; i < EEPROM_Vector.size();i++){
            EEPROM_Vector.at(i)->Retrieve();
        }
    }

    void EEPROM_Manager::Reset(){
        for(size_t i=0; i < EEPROM_Vector.size();i++){
            EEPROM_Vector.at(i)->Reset();
        }
    }

    bool EEPROM_Manager::Add(EEPROM_Variable* variable,uint8_t EEPROM_LOC){
        if(EEPROM_LOC>E2END/4){
            overflow_error.push_back(EEPROM_LOC);
            return(false);
        }
        if(EEPROM_MAP & (1U << EEPROM_LOC) ){ // if the EEPROM memory location is already taken then return false 
            double_error.push_back(EEPROM_LOC);
            return(false);
        }
        EEPROM_MAP |= (1U << EEPROM_LOC);
        EEPROM_Vector.push_back(variable);
        return(true);
    }

    void EEPROM_Manager::print_errors(){
        if(double_error.size()>0){
            Serial.print("Multiple Variables were initialised at locations: \n");
        for(size_t i=0;i<double_error.size();i++){
            Serial.print(double_error.at(i));
            Serial.print("\n");

        }}
        if(overflow_error.size()>0){
            Serial.print("Variables were initialised outside of EEPROM: \n");
        for(size_t i=0;i<overflow_error.size();i++){
            Serial.print(overflow_error.at(i));
            Serial.print("\n");

        }}
        
    }

