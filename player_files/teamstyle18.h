#pragma once
#include<string>
#include<iostream>
#include<vector>
using std::string;
using std::vector;
extern int team_id = -1; //����id

//type_name
enum UnitType
{
	BASE,	     //������
	INFANTRY,		 //����
	VEHICLE,		 //̹��
	AIRCRAFT,		 //�ɻ�
	BUILDING   	 //����
};
enum BuffType
{
	HEALTH,	            //�������ֵbuff
	ATTACK,		            //����buff
	SPEED,		            //�ٶ�buff
	DEFENSE,		        //����buff
	SHOT_RANGE 		//���buff
};

enum TypeName
{
	  __BASE, 

	  MEAT, HACKER, SUPERMAN,

	  BATTLE_TANK, BOLT_TANK, NUKE_TANK, 

	  UAV, EAGLE, 

	  HACK_LAB, BID_LAB, CAR_LAB, ELEC_LAB, RADIATION_LAB, 
	  UAV_LAB, AIRCRAFT_LAB, BUILD_LAB, FINANCE_LAB, MATERIAL_LAB,
	  NANO_LAB, TEACH_BUILDING, BANK,
	  Type_num
};

enum attribute
{
	UNIT_TYPE,
	ORIGIN_MAX_HEALTH,
	ORIGIN_MAX_SPEED,
	ORIGIN_SHOT_RANGE,
	ORIGIN_DEFENSE,
	ORIGIN_ATTACK,
	SKILL_CD_1,
	SKILL_CD_2,
	MAX_ACCOUNT,
	PEOPLE_COST,
	MONEY_COST,
	TECH_COST,
	attribute_num
};


struct Position
{
	int x;
	int y;
};

const int origin_attribute[Type_num][attribute_num] =
{

{BASE,      10000  ,  0,   10,  0,    10,  -1,   1,   0,     0,   0,     0      },
{INFANTRY,	100    ,  3,   1,   10,   0,   -1,  -1,   -1,    1,   100,   0	    },
{INFANTRY,	150    ,  3,   18,  20,   0,   1,   -1,   -1,    2,   600,   300	},
{INFANTRY,	500    ,  4,   10,  150,  15,  1,   50,   1,     10,  2000,  1500	},
{VEHICLE,	900    ,  7,   14,  200,  100, 10,  -1,   -1,    4,   1500,  600	},
{VEHICLE,	500    ,  6,   12,  100,  200, 10,  -1,   -1,    3,   1000,  500	},
{VEHICLE,	700    ,  5,   20,  150,  300, 10,  150,  1,     10,  4000,  2000	},
{AIRCRAFT,	300    ,  12,  10,  50,   5,   1,   -1,   -1,    2,   400,   100	},
{AIRCRAFT,	600    ,  15,  16,  200,  200, 20,  50,   1,     1,   3000,  1500	},
{BUILDING,	INT_MAX,  0,   0,   0,    0,   -1,  -1,   0,     0,   0,     0	    },
{BUILDING,	INT_MAX,  0,   0,   0,    0,   -1,  -1,   0,     0,   0,     0	    },
{BUILDING,	INT_MAX,  0,   0,   0,    0,   -1,  -1,   0,     0,   0,     0	    },
{BUILDING,	INT_MAX,  0,   0,   0,    0,   -1,  -1,   0,     0,   0,     0	    },
{BUILDING,	INT_MAX,  0,   0,   0,    0,   -1,  -1,   0,     0,   0,     0	    },
{BUILDING,	INT_MAX,  0,   0,   0,    0,   -1,  -1,   0,     0,   0,     0	    },
{BUILDING,	INT_MAX,  0,   0,   0,    0,   -1,  -1,   0,     0,   0,     0	    },
{BUILDING,	INT_MAX,  0,   0,   0,    0,   -1,  -1,   0,     0,   0,     0	    },
{BUILDING,	INT_MAX,  0,   0,   0,    0,   -1,  -1,   0,     0,   0,     0	    },
{BUILDING,	INT_MAX,  0,   0,   0,    0,   -1,  -1,   0,     0,   0,     0	    },
{BUILDING,	INT_MAX,  0,   0,   0,    0,   -1,  -1,   0,     0,   0,     0	    },
{BUILDING,	INT_MAX,  0,   0,   0,    0,   -1,  -1,   0,     0,   0,     0	    },
{BUILDING,	INT_MAX,  0,   0,   0,    0,   -1,  -1,   0,     0,   0,     0	    }

};


class Unit
{
public:
	int unit_id = 0;				// ��λid
	string name = "";				// ��λ���֣���ѡ����ͧһ��
	Position position;				// ��λλ�ã�Ŀ����һ��point֮��Ķ���
	int flag = -1;					// ������Ӫ	
	int motor_type;					// �ƶ���ʽ���ֵ���Ϳ��У���Ӣ�����ļ��ܻ��õ�

	UnitType unit_type;
	TypeName type_name;

	int max_health_now;				// ��ǰHP����
	int health_now;					// ��ǰ����ֵ
	int max_speed_now;				// ��ǰ����ٶ�
	int shot_range_now;				// ��ǰ���(�ֽ׶�ò��û��������̵ļ��ܣ������ȱ���)
	int defense_now;				// ��ǰ����
	int attack_now;					// ��ǰ����
	double healing_rate = 0;		// ���� / ά������
	int hacked_point;				// ���ڵĵ���
	bool is_disable = false;		// �Ƿ�̱��
	int disable_since;				// ��̱����ʱ��㣬�����ж�̱��ʱ��
	int skill_last_release_time1;	// �ϴμ���1�ͷ�ʱ��
	int skill_last_release_time2;	// �ϴμ���2�ͷ�ʱ��
	int attack_mode;				// ����ģʽ������ɶԿգ��ɶ�̹�ˣ��ɶԲ���֮���

	Unit(int unit_id, int flag, TypeName type_name, Position pos);
};


std::ostream& operator <<(std::ostream &os, const Unit&u)//��Ҳ���������Ե�
{

	os << "id:" << u.unit_id << "��Ӫ:" << u.flag << "λ��:" << " (" << u.position.x << "," << u.position.y << ") " << "����:" << u.unit_type << "����:" << u.type_name << "�Զ�����:" << u.name <<
		"HP:" << u.health_now << "MAXHP:" << u.max_health_now << "�ٶ�:" << u.max_speed_now << "���:" << u.shot_range_now << "����:" << u.defense_now << "����:" << u.attack_now <<
		"�������:" << origin_attribute[u.type_name][MAX_ACCOUNT] <<
		"�˿�:" << origin_attribute[u.type_name][PEOPLE_COST] <<
		"��Ǯ����:" << origin_attribute[u.type_name][MONEY_COST] <<
		"�Ƽ�����:" << origin_attribute[u.type_name][TECH_COST] <<
		std::endl;
	return os;
}
