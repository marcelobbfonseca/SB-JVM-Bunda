#include"DadosDaInstancia.hpp"

DadosDaInstancia::DadosDaInstancia(JavaClass *javaClass){

	field_info *fields = javaClass->getFieldInfo();
	uint16_t abstractFlag = 0x0400;

	if ((javaClass.getAccessFlags() & abstractFlag) != 0) {

		// Não pode instanciar se for classe abstrata
		cerr << "Erro de intanciamento" << endl;
		exit(1);

	}

	for (int i = 0; i < JavaClass.getFieldsCount(); i++) {

		field_info field = fields[i];
		uint16_t staticAndFinalFlag = 0x0008 | 0x0010;

		if ((field.access_flags & staticAndFinalFlag) == 0) { // não estática e não final

			string nomeField = JavaClass.getUTF8(field.name_index);
			string descritorField = JavaClass.getUTF8(field.descriptor_index);

			char tipoField = descritorField[0];
			Valor valor;

			switch (tipoField) {
				case 'B':
					valor.tipo = TipoDado::BYTE;
					break;
				case 'C':
					valor.tipo = TipoDado::CHAR;
					break;
				case 'D':
					valor.tipo = TipoDado::DOUBLE;
					break;
				case 'F':
					valor.tipo = TipoDado::FLOAT;
					break;
				case 'I':
					valor.tipo = TipoDado::INT;
					break;
				case 'J':
					valor.tipo = TipoDado::LONG;
					break;
				case 'S':
					valor.tipo = TipoDado::SHORT;
					break;
				case 'Z':
					valor.tipo = TipoDado::BOOLEAN;
					break;
				default:
					valor.tipo = TipoDado::REFERENCE;
			}

			valor.dado = 0;
			fieldsInstancia[nomeField] = valor;
		}
	}

	// Quando um objeto é criado, ele precisa ser armazenado na Heap
	Heap &heap = Heap::getInstance();
	heap.adcObjeto(this);
}

/*Pra que serve isso tudo ??
ClassInstance::~ClassInstance() {

}

ObjectType ClassInstance::objectType() {
	return ObjectType::CLASS_INSTANCE;
}

ClassRuntime* ClassInstance::getClassRuntime() {
	return _classRuntime;
}

void ClassInstance::putValueIntoField(Value value, string fieldName) {
	_fields[fieldName] = value;
}

Value ClassInstance::getValueFromField(string fieldName) {
	if (_fields.count(fieldName) ==  0) {
		cerr << "NoSuchFieldError" << endl;
		exit(1);
	}

	return _fields[fieldName];
}

bool ClassInstance::fieldExists(string fieldName) {
	return _fields.count(fieldName) > 0;
}
*/
