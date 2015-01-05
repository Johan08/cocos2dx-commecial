//
//  DBUtil.h
//  CatchMaster
//
//  Created by sxz on 2015/01/02.
//  Copyright 2015年 hibiya.tech@gmail.com. All rights reserved.

#ifndef CatchMaster_DBUtil_H
#define CatchMaster_DBUtil_H

#include<iostream>

#include "cocos2d.h"
#include "sqlite3.h"

USING_NS_CC;

class DBUtil {
    
private:
    
    //数据库
    sqlite3* m_pDataBase;
    
private:
    
#pragma mark <构造 && 析构>
    
    DBUtil();
    
    virtual ~DBUtil();
    
    public :
    
#pragma mark <创建 && 销毁单例>
    
    static DBUtil* getInstance();
    
    static void destoryInstance();
    
#pragma mark <数据库操作>
    
    /**
     *  打开数据库(创建)
     *
     *  @param aDataBaseName 数据库名
     */
    void openDBWithName(std::string aDataBaseName);
    
    /**
     *  关闭数据库
     */
    void closeDB();
    
    /**
     *  创建数据表
     *
     *  @param aSql       建表sql语句
     *  @param aTableName 表名
     */
    void createTable(std::string aSql, std::string aTableName);
    
    /**
     *  通过表名查询该表是否存在
     *
     *  @param aTabelName 表秒
     *
     *  @return true: 存在 false: 不存在
     */
    bool isExistTableByName(std::string aTabelName);
    
    /**
     *  删除数据表
     *
     *  @param aSql       删表sql语句
     *  @param aTableName 表名
     */
    void deleteTable(std::string aSql, std::string aTableName);
    
    /**
     *  插入记录
     *
     *  @param aSql 插入数据sql语句
     */
    void insertData(std::string aSql);
    
    /**
     *  删除记录
     *
     *  @param aSql 删除数据sql语句
     */
    void deleteData(std::string aSql);
    
    /**
     *  修改记录
     *
     *  @param aSql 修改数据sql语句
     */
    void updateData(std::string aSql);
    
    /**
     *  查询记录
     *
     *  @param aSql     修改数据sql语句
     */
    std::vector<std::map<std::string, std::string> >searchData(std::string aSql);
    
    /**
     *  查询记录的条数
     *
     *  @param sql 查询记录sql语句
     *
     *  @return 记录条数
     */
    int searchDataCount(std::string aSql);
    
    /**
     *  开始事务
     *
     *  @return 操作结果(sqlite3提供的宏)
     */
    int beginTransaction();
    
    /**
     *  提交事务(失败回滚)
     *
     *  @param aResult       操作结果
     *
     *  @return 操作结果(sqlite3提供的宏)
     */
    int comitTransaction(int aResult);
    
};
#endif //CatchMaster_DBUtil_H
