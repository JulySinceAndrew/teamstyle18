//��ѡ�ֽӿڶ�����֮����ȷ��
#include "teamstyle18-my-1.h"

#include <queue>
using namespace std;
 //��ô�죿����
extern queue <Instr>  q_instruction;
extern resourse allResourse;
extern double buff[40]; //buffȫ�ֱ��� ��Ӫ1[��λ����][buff����]
extern Unit * all_unit;			  //���е�unit
extern int all_unit_size;				//��¼����unit�ĸ���
extern bool team_id;
template <typename Data> 
void safeQueue<Data>::safePush(Data value)
{
	mtx.lock();
	squeue.push();
	mtx.unlock();
}
template <typename Data> 
void safeQueue<Data>::safePop(void)
{
	;
}
template <typename Data> 
Data safeQueue<Data>::safeFront(void)
{
	;
}
/*
//extern double buff1[4][5]; //buffȫ�ֱ��� ��Ӫ1[��λ����][buff����]
//extern double buff2[4][5]; //buffȫ�ֱ��� ��Ӫ2[��λ����][buff����]
extern double buff_1[20]; //buffȫ�ֱ��� ��Ӫ1[��λ����][buff����]
extern double buff_2[20]; //buffȫ�ֱ��� ��Ӫ2[��λ����][buff����]
extern Unit * all_unit_1;			  //��Ӫ1������֪�������е�unit
extern int all_unit_size_1;				//��¼��Ӫ1����unit�ĸ���
extern Unit * all_unit_2;			  //��Ӫ2������֪�������е�unit
extern int all_unit_size_2;				//��¼��Ӫ1����unit�ĸ���
*/

//���캯��
Unit::Unit(){};
Unit::Unit(int _unit_id, int _flag, TypeName _type_name, Position pos)
{

	unit_id = _unit_id;
	flag = _flag;
	position = pos;
	type_name = _type_name;
	unit_type = UnitType(origin_attribute[type_name][UNIT_TYPE]);
	health_now = origin_attribute[type_name][ORIGIN_MAX_HEALTH] * (1 + buff[20*flag+5*unit_type+HEALTH]);	//�ӡ�double��ת������int�������ܶ�ʧ����	  //��λ����ʱĬ��Ϊ���Ѫ��������ͬ��
	max_health_now = origin_attribute[type_name][ORIGIN_MAX_HEALTH] * (1 + buff[20*flag+5*unit_type+HEALTH]);
	max_speed_now = origin_attribute[type_name][ORIGIN_MAX_SPEED] * (1 + buff[20*flag+5*unit_type+SPEED]);
	shot_range_now = origin_attribute[type_name][ORIGIN_SHOT_RANGE] * (1 + buff[20*flag+5*unit_type+SHOT_RANGE]);
	defense_now = origin_attribute[type_name][ORIGIN_DEFENSE] * (1 + buff[20*flag+5*unit_type+DEFENSE]);
	attack_now = origin_attribute[type_name][ORIGIN_ATTACK] * (1 + buff[20*flag+5*unit_type+ATTACK]);

}
void Unit::Print()
{
	cout<<"what i get"<<endl;
	cout<<type_name<<endl;
	cout<<unit_type<<endl;
	cout<<attack_mode<<endl;			// ����ģʽ������ɶԿգ��ɶ�̹�ˣ��ɶԲ���֮���
	cout<<attack_now<<endl;					// ��ǰ����
	cout<<defense_now<<endl;				// ��ǰ����
	cout<<disable_since<<endl ;			// ��̱����ʱ��㣬�����ж�̱��ʱ��
	cout<<flag <<endl;					// ������Ӫ
	cout<<hacked_point<<endl;				// ���ڵĵ���
	cout<<healing_rate <<endl;		// ���� / ά������	
	cout<<health_now<<endl;					// ��ǰ����ֵ		
	cout<<is_disable<<endl;		// �Ƿ�̱��
	cout<<max_health_now<<endl;				// ��ǰHP����
	cout<<max_speed_now<<endl;				// ��ǰ����ٶ�
	cout<<position.x<<endl;				// ��λλ�ã�Ŀ����һ��point֮��Ķ���
	cout<<position.y<<endl;	
	cout<<shot_range_now<<endl;				// ��ǰ���(�ֽ׶�ò��û��������̵ļ��ܣ������ȱ���)
	cout<<skill_last_release_time1<<endl;// �ϴμ���1�ͷ�ʱ��
	cout<<skill_last_release_time2<<endl;// �ϴμ���2�ͷ�ʱ��
	cout<<unit_id<<endl;				// ��λid
}
Instr::Instr(int instru_type,int u_id,int tar_build_id,Position tpos1,Position tpos2):instruction_type(instru_type),the_unit_id(u_id),target_id_building_id(tar_build_id),pos1(tpos1),pos2(tpos2){};


//1��ʾskkil1,2��ʾskkil2,3��ʾproduce,4��ʾMove,5��ʾcapture
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
	using namespace std;
	
	Instr Isttemp(3,-1,building_id);
	cout<<"in produce 1 "<<q_instruction.size()<<endl;
	//q_instruction.push(Isttemp);
	cout<<"in produce 2 "<<q_instruction.size()<<endl;
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
resourse getResourse(void)
{
	return allResourse;
}
bool getTeamId(void)
{
	return team_id;
}
void NewData(void)
{
	;
}
/*class Instr							//�Ѽ���ָ������ݶ��ŵ��������
{
public:
	int instruction_type;				//1��ʾskkil1,2��ʾskkil2,3��ʾproduce,4��ʾMove,5��ʾcapture
	int the_unit_id;
	int target_id_building_id;
	Position_x_y pos1;					//ΪʲôҪ��struct?
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
double buff1[4][5] = { 0.0 }; //buffȫ�ֱ��� ��Ӫ1[��λ����][buff����]
double buff2[4][5] = { 0.0 }; //buffȫ�ֱ��� ��Ӫ2[��λ����][buff����]
Unit * all_unit_1 = new Unit[1];			  //��Ӫ1������֪�������е�unit
int all_unit_size_1=0;				//��¼��Ӫ1����unit�ĸ���
Unit * all_unit_2 = new Unit[1];			  //��Ӫ2������֪�������е�unit
int all_unit_size_2=0;				//��¼��Ӫ2����unit�ĸ���
*/