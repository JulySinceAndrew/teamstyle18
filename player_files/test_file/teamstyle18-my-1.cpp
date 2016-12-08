//与选手接口端商量之后再确定
#include "teamstyle18-my-1.h"

#include <queue>
using namespace std;
 //怎么办？？？
extern queue <Instr>  q_instruction;
extern resourse resourse_of_1;
extern resourse resourse_of_2;
extern double buff[40]; //buff全局变量 阵营1[单位类型][buff类型]
extern Unit * all_unit;			  //所有的unit
extern int all_unit_size;				//记录所有unit的个数
extern bool team_id;
/*
//extern double buff1[4][5]; //buff全局变量 阵营1[单位类型][buff类型]
//extern double buff2[4][5]; //buff全局变量 阵营2[单位类型][buff类型]
extern double buff_1[20]; //buff全局变量 阵营1[单位类型][buff类型]
extern double buff_2[20]; //buff全局变量 阵营2[单位类型][buff类型]
extern Unit * all_unit_1;			  //阵营1，可以知道的所有的unit
extern int all_unit_size_1;				//记录阵营1所有unit的个数
extern Unit * all_unit_2;			  //阵营2，可以知道的所有的unit
extern int all_unit_size_2;				//记录阵营1所有unit的个数
*/

//构造函数
Unit::Unit(){};
Unit::Unit(int _unit_id, int _flag, TypeName _type_name, Position pos)
{

	unit_id = _unit_id;
	flag = _flag;
	position = pos;
	type_name = _type_name;
	unit_type = UnitType(origin_attribute[type_name][UNIT_TYPE]);
	health_now = origin_attribute[type_name][ORIGIN_MAX_HEALTH] * (1 + buff[20*flag+5*unit_type+HEALTH]);	//从“double”转换到“int”，可能丢失数据	  //单位生成时默认为最大血量，以下同理
	max_health_now = origin_attribute[type_name][ORIGIN_MAX_HEALTH] * (1 + buff[20*flag+5*unit_type+HEALTH]);
	max_speed_now = origin_attribute[type_name][ORIGIN_MAX_SPEED] * (1 + buff[20*flag+5*unit_type+SPEED]);
	shot_range_now = origin_attribute[type_name][ORIGIN_SHOT_RANGE] * (1 + buff[20*flag+5*unit_type+SHOT_RANGE]);
	defense_now = origin_attribute[type_name][ORIGIN_DEFENSE] * (1 + buff[20*flag+5*unit_type+DEFENSE]);
	attack_now = origin_attribute[type_name][ORIGIN_ATTACK] * (1 + buff[20*flag+5*unit_type+ATTACK]);

}
Instr::Instr(int instru_type,int u_id,int tar_build_id,Position tpos1,Position tpos2):instruction_type(instru_type),the_unit_id(u_id),target_id_building_id(tar_build_id),pos1(tpos1),pos2(tpos2){};


//1表示skkil1,2表示skkil2,3表示produce,4表示Move,5表示capture
//team1
void skill_1(int unit_id,int target_id,Position tpos1,Position tpos2) 
{
	Instr Isttemp(1,unit_id,target_id,tpos1,tpos2);
	q_instruction.push(Isttemp);
}
void skill_2(int unit_id,int target_id,Position tpos1,Position tpos2) 
{
	Instr Isttemp(2,unit_id,target_id,tpos1,tpos2);
	q_instruction.push(Isttemp);
}
void produce(int building_id)
{
	Instr Isttemp(3,-1,building_id);
	q_instruction.push(Isttemp);
}
void Move(int unit_id, Position pos)
{
	Instr Isttemp(4,unit_id,-1,pos);
	q_instruction.push(Isttemp);
}
void capture(int unit_id, int building_id)
{
	Instr Isttemp(5,unit_id,building_id);
	q_instruction.push(Isttemp);
}
Unit * getUnit(void)
{
	return all_unit;
}
int getUnitSize(void)
{
	return all_unit_size;
}
double * getBuff(void)
{
	return buff;
}
resourse getResourse_1(void)
{
	return resourse_of_1;
}
resourse getResourse_2(void)
{
	return resourse_of_2;
}
bool getTeamId(void)
{
	return team_id;
}
void NewData(void)
{
	;
}
/*class Instr							//把几种指令的数据都放到这个里面
{
public:
	int instruction_type;				//1表示skkil1,2表示skkil2,3表示produce,4表示Move,5表示capture
	int the_unit_id;
	int target_id_building_id;
	Position_x_y pos1;					//为什么要加struct?
	Position_x_y pos2;
	Instr(int instru_type=-1,int u_id=-1,int tar_build_id=-1,Position_x_y tpos1=(-1,-1),Position_x_y tpos2=(-1,-1));
};*/
/*
//team1
Unit * getUnit_1(void)
{
	return all_unit_1;
}
int getUnitSize_1(void)
{
	return all_unit_size_1;
}
double * getBuff_1(void)
{
	return buff_1;
}
resourse getResourse_1(void)
{
	return resourse_of_1;
}
*/
/*
resourse resourse_of_1;
resourse resourse_of_2;
double buff1[4][5] = { 0.0 }; //buff全局变量 阵营1[单位类型][buff类型]
double buff2[4][5] = { 0.0 }; //buff全局变量 阵营2[单位类型][buff类型]
Unit * all_unit_1 = new Unit[1];			  //阵营1，可以知道的所有的unit
int all_unit_size_1=0;				//记录阵营1所有unit的个数
Unit * all_unit_2 = new Unit[1];			  //阵营2，可以知道的所有的unit
int all_unit_size_2=0;				//记录阵营2所有unit的个数
*/