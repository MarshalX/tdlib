from jinja2 import Environment, FileSystemLoader


PATH_TO_SCHEMA = '../../../third_party/td/td/generate/scheme/td_api.tl'

SCHEMA_SEPARATOR = '---functions---'

CLASS_DESCRIPTION_START = '//@description '

ABSTRACT_CLASS_START = '//@class '
ABSTRACT_CLASS_DESCRIPTION_START = '@description '

COMMENT = '//'
MULTILINE_COMMENT = '//-'

INLINE_SEPARATOR = '@'
MULTILINE_SEPARATOR = '//@'
CONSTRUCTOR_DEFINITION_SEPARATOR = '='
ARG_DEFINITION_SEPARATOR = ':'

END_OF_DEFINITION = ';'

env = Environment(loader=FileSystemLoader('templates'))
template = env.get_template('tdlib_native.cpp.template')


if __name__ == '__main__':
    can_be_a_class = True
    class_describing = False

    abstract_classes = list()
    classes = list()

    args_to_description_temp = dict()
    current_arg = None

    current_class_desc = None

    with open(PATH_TO_SCHEMA, 'r') as scheme:
        lines = scheme.read().splitlines()
        for line in lines:
            # multiline description of the arg
            if line.startswith(MULTILINE_COMMENT) and current_arg:
                args_to_description_temp[current_arg] += f' {line.replace(MULTILINE_COMMENT, "")}'
                continue
            # multiline description of the class
            elif line.startswith(MULTILINE_COMMENT) and can_be_a_class:
                current_class_desc += f' {line.replace(MULTILINE_COMMENT, "")}'
                continue

            if class_describing:
                if not line.startswith(COMMENT):
                    constructor_info, returned_type = line.split(CONSTRUCTOR_DEFINITION_SEPARATOR)
                    returned_type = returned_type.replace(END_OF_DEFINITION, '').replace(' ', '')
                    class_name, *constructor_args = constructor_info.split()

                    # there is
                    # class name == constructor name
                    # constructor args == class fields

                    detailed_args = list()
                    for arg in constructor_args:
                        name, type_ = arg.split(ARG_DEFINITION_SEPARATOR)

                        detailed_args.append({
                            'name': name,
                            'type': type_,
                            'desc': args_to_description_temp.get(name, '')
                        })

                    classes.append({
                        'name': class_name,
                        'desc': current_class_desc,
                        'returned_type': returned_type,
                        'args': detailed_args,
                    })

                    args_to_description_temp.clear()
                    current_arg = None
                    current_class_desc = None
                    class_describing = False

                    continue

                arg_info = line.split(MULTILINE_SEPARATOR)[1].split(maxsplit=1)
                arg_name = arg_info[0]
                arg_desc = arg_info[1]

                current_arg = arg_name
                args_to_description_temp[arg_name] = arg_desc

                continue

            if line == SCHEMA_SEPARATOR:
                can_be_a_class = False
                continue

            if line.startswith(ABSTRACT_CLASS_START) and can_be_a_class:
                if line.startswith(COMMENT):
                    line = line[len(COMMENT):]

                class_info = line.split(INLINE_SEPARATOR)
                class_name = class_info[1].rsplit(maxsplit=1)[1]
                class_desc = class_info[2].split(maxsplit=1)[1]

                abstract_classes.append({
                    'name': class_name,
                    'desc': class_desc
                })
            elif line.startswith(CLASS_DESCRIPTION_START) and can_be_a_class:
                if line.startswith('//@description Sets the phone number '):
                    print('kek')

                current_class_desc = line.split(CLASS_DESCRIPTION_START, 1)[1]
                class_describing = True

            # TODO functions

    code = template.render(abstract_classes=abstract_classes, classes=classes)
    with open('../../native/tdlib.cpp', 'w') as output:
        output.write(code)
