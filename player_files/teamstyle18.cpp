#pragma once
#include "teamstyle18.h"

vector<Unit>units;      // ��λList
int turn_num = 0;   //�غ���
extern double buff[2][4][5] = { 0.0 }; //buffȫ�ֱ��� [��Ӫ][��λ����][buff����]

Unit::Unit(int _unit_id, int _flag, TypeName _type_name, Position pos)
{

	unit_id = _unit_id;
	flag = _flag;
	position = pos;
	type_name = _type_name;
	unit_type = UnitType(origin_attribute[type_name][UNIT_TYPE]);
	health_now = origin_attribute[type_name][ORIGIN_MAX_HEALTH] * (1 + buff[flag][unit_type][HEALTH]);		  //��λ����ʱĬ��Ϊ���Ѫ��������ͬ��
	max_health_now = origin_attribute[type_name][ORIGIN_MAX_HEALTH] * (1 + buff[flag][unit_type][HEALTH]);
	max_speed_now = origin_attribute[type_name][ORIGIN_MAX_SPEED] * (1 + buff[flag][unit_type][SPEED]);
	shot_range_now = origin_attribute[type_name][ORIGIN_SHOT_RANGE] * (1 + buff[flag][unit_type][SHOT_RANGE]);
	defense_now = origin_attribute[type_name][ORIGIN_DEFENSE] * (1 + buff[flag][unit_type][DEFENSE]);
	attack_now = origin_attribute[type_name][ORIGIN_ATTACK] * (1 + buff[flag][unit_type][ATTACK]);

}



void skill(int unit_id,SkillInstr skitr) {};
//����ʱ��дskill(2333, SkillInstr(233))����skill(2333, SkillInstr({20��30}))����skill(2333, SkillInstr({20��30}), SkillInstr({40��50}))

void produce(int building_id){};
void Move(int unit_id, Position pos){};
void capture(int unit_id, int building_id){};



int main()//�����������Ե�
{
	units.push_back(Unit(1, 1, NUKE_TANK, { 22,33 }));
	units[0].name = "59��,��Ը�����";
    std::cout<<units[0];
}