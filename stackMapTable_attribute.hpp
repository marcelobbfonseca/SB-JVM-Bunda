/*In a class file whose version number is greater than or equal to 50.0, if a method's
Code attribute does not have a StackMapTable attribute, it has an implicit stack
map attribute. This implicit stack map attribute is equivalent to a StackMapTable
attribute with number_of_entries equal to zero.*/

#include<stdint.h>
#include<stdio.h>
#include<vector>

#ifndef STACKMAPTABLE_ATTRIBUTE_HPP
#define STACKMAPTABLE_ATTRIBUTE_HPP

enum classesValues
{
	SAME; /* 0-63 */,0
	SAME_LOCALS_1_STACK_ITEM /* 64-127 */,64
	SAME_LOCALS_1_STACK_ITEM_EXTENDED /* 247 */,247
	CHOP /* 248-250 */,248
	SAME_FRAME_EXTENDED /* 251 */,251
	APPEND /* 252-254 */,252
    FULL_FRAME /* 255 */,255
	ITEM_Top/* 0 */,0
    ITEM_Integer /* 1 */,1
    ITEM_Float /* 2 */,2
    ITEM_Long/* 4 */,4
    ITEM_Double /* 3 */,3
    ITEM_Null/* 5 */,5
    ITEM_UninitializedThis; /* 6 */,6
    ITEM_Object/* 7 */,7
    ITEM_Uninitialized /* 8 */,8

};

class stackMapTable_attribute {

    uint16_t attribute_name_index;
    uint32_t attribute_length;
    uint16_t number_of_entries;
    vector<stack_map_frame> entries;

    union stack_map_frame {

        same_frame same_frame;
        same_locals_1_stack_item_frame same_locals_1_stack_item_frame;
        same_locals_1_stack_item_frame_extended same_locals_1_stack_item_frame_extended;
        chop_frame chop_frame;
        same_frame_extended same_frame_extended;
        append_frameappend_frame;
        full_framefull_frame;
    }

    union verification_type_info {

        Top_variable_info top_variable_info;
        Integer_variable_info integer_variable_info;
        Float_variable_info float_variable_info;
        Long_variable_info long_variable_info;
        Double_variable_info double_variable_info;
        Null_variable_info null_variable_info;
        UninitializedThis_variable_info uninitializedThis_variable_info;
        Object_variable_info object_variable_info;
        Uninitialized_variable_info uninitialized_variable_info;

    }

    class same_frame {

        uint8_t frame_type = SAME; /* 0-63 */

    }

    class same_locals_1_stack_item_frame {

        uint8_t frame_type = SAME_LOCALS_1_STACK_ITEM; /* 64-127 */
        verification_type_info stack;//stack tem tamanho 1

    }

    class same_locals_1_stack_item_frame_extended {

        uint8_t frame_type = SAME_LOCALS_1_STACK_ITEM_EXTENDED; /* 247 */
        uint16_t offset_delta;
        vectorverification_type_info stack;

    }

    class chop_frame {

        uint8_t frame_type = CHOP; /* 248-250 */
        uint16_t offset_delta;
    }

    class same_frame_extended {

        uint8_t frame_type = SAME_FRAME_EXTENDED; /* 251 */
        uint16_t offset_delta;

    }

    class append_frame {

        uint_8 frame_type = APPEND; /* 252-254 */
        uint_16 offset_delta;
        vector<verification_type_info> locals;//locals[frame_type - 251]

    }

    class full_frame {

        uint8_t frame_type = FULL_FRAME; /* 255 */
        uint16_t offset_delta;
        uint16_t number_of_locals;
        vector<verification_type_info> locals;//locals[number_of_locals]
        uint16_t number_of_stack_items;
        vector<verification_type_info> stack;//stack[number_of_stack_items]
    }

    class Top_variable_info {

        uint8_t tag = ITEM_Top; /* 0 */

    }

    class Integer_variable_info {

        uint8_t tag = ITEM_Integer; /* 1 */
    }

    class Float_variable_info {

        uint8_t tag = ITEM_Float; /* 2 */

    }

    class Long_variable_info {

    uint8_t tag = ITEM_Long; /* 4 */

    }

    class Double_variable_info {

        uint8_t tag = ITEM_Double; /* 3 */
    }

    class Null_variable_info {

        uint8_t tag = ITEM_Null; /* 5 */

    }

    UninitializedThis_variable_info {

        uint8_t tag = ITEM_UninitializedThis; /* 6 */
    }

    Object_variable_info {

        uint8_t tag = ITEM_Object; /* 7 */
        uint16_t cpool_index;

    }

    class Uninitialized_variable_info {

        uint8_t tag = ITEM_Uninitialized /* 8 */
        uint16_t offset;
    }



    public:

	stackMapTable_attribute(FILE *arq);
	~stackMapTable_attribute ();
	void ExibirInformacoes(void);
}

#endif
