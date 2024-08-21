# Converts all the file from a folder to vs code snippet

import argparse
import os
import json

if __name__ == '__main__':
    # Parsing
    parser = argparse.ArgumentParser(description="First line of file should be a comment containing word 'template' to identify it as a potential snippet file. Second Line should be a comment containing template prefix. Third line should be a comment containing the template description. Snippet will start after an empty comment")
    parser.add_argument('-s', help="Address of snippet file", metavar="snippet_file")
    parser.add_argument('-t', help="Address of template folder", metavar="template_folder")
    parser.add_argument('-l', help="Language of snippets. Currently only for cpp", metavar="language")
    args = parser.parse_args()

    snippet_file = args.s
    template_folder = args.t
    language = args.l
    if language not in ['cpp']:
        raise Exception(f"{language} files are not supported")
    
    # Selecting snipper files
    file_address = []
    for file in os.listdir(template_folder):
        if language in file.split("."):
            file_address.append((os.path.join(template_folder, file), file[:file.find(".")]))
    
    snippet = {}
    for file in file_address:
        with open(file[0], 'r') as f:
            temp_name = file[1]
            first_line = f.readline()
            if language == 'cpp':
                if first_line.strip() != '// template':
                    continue
                temp_prefix = f.readline().strip()[2:].strip()
                temp_desc = f.readline().strip()[2:].strip()
                temp_body = f.readlines()
                for i in range(len(temp_body)):
                    if temp_body[i].strip() == '//':
                        temp_body = temp_body[i+1:]
                        break
                else:
                    raise Exception("No starting point marked by empty comment")
                for i in range(len(temp_body)):
                    if temp_body[i][-1] == '\n':
                        temp_body[i] = temp_body[i][:-1]
            snip = {
                "scope": language,
                "prefix": temp_prefix,
                "body": temp_body,
                "description": temp_desc
            }
            snippet[temp_name] = snip

    with open(snippet_file, "w") as f:
        json.dump(snippet, f, indent=4)