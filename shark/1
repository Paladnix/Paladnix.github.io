#!/usr/local/bin/python3
# coding=utf-8

import sys
import yaml
import os
import requests
import json


def create_problem(problem):
    url = 'https://codeshark.cn/api/written-problem/create'
    r = requests.post(url, json = problem)
    print("%s\n" % r.text)
    


def check_field(problem):

    if 'description' not in problem or problem['description'] == "":
        print("error Field: description ")
        return False
    if 'answer' not in problem or problem['answer'] == "":
        print("error Field: answer")
        return False
    if 'type' not in problem or problem['type'] not in ['SIMPLE', 'MULTI', 'FILL']:
        print("error Field: type")
        return False
    if problem['type'] != 'FILL':
        if 'options' not in problem or len(problem['options']) == 0:
            print("error Field: type")
            return False
    if problem['type'] == 'SIMPLE':
        if len(problem['answer']) != 1:
            print("error Field: answer")
            return False

    if 'source' not in problem or len(problem['source']) == 0:
        print("error Field: source")
        return False

    return True


def read_and_create_problem(yaml_file):
    yaml_data = {}
    with open(yaml_file, 'r', encoding='utf-8') as f:
        yaml_data = yaml.load(f, Loader=yaml.Loader)

    for problem in yaml_data: 
        # check field and value
        if not check_field(problem):
            return 

    for problem in yaml_data: 
        create_problem(problem)
        

if __name__ == '__main__':
    if len(sys.argv) == 1:
        print("缺少参数： yaml文件")
        exit(1)
    read_and_create_problem(sys.argv[1])


