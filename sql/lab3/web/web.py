from flask import Flask, render_template, redirect, request, session, flash
from datetime import timedelta
import pymysql

app = Flask(__name__)
app.secret_key = "Hello world"


def calint(string):
    if not string:
        return '0'
    else:
        return string


def usesql(sentence):
    db = pymysql.connect(host='localhost', user='root',
                         passwd='voyage', database='lab3')
    cursor = db.cursor()
    print(sentence)
    cursor.execute(sentence)
    tmp = cursor.fetchall()
    db.commit()
    cursor.close()
    db.close()
    return tmp


def updatepost(num):
    teacherlist = usesql('select * from teacher')
    teacherdata = {}
    for item in teacherlist:
        teacherdata[item[0]] = item[1]
    paperlist = usesql('select * from Paper')
    paperdata = {}
    for item in paperlist:
        paperdata[item[0]] = item[1]
    postlist = usesql('select * from PostPaper')
    anslist = []
    for item in postlist:
        if num == 2 and item[1] != int(calint(request.form.get('papid'))):
            continue
        anslist.append({'teid': item[0],
                        'teacher': teacherdata[item[0]],
                        'paid': item[1],
                        'paname': paperdata[item[1]],
                        'rank': item[2],
                        'isau': '是' if item[3] == True else '否'
                        })
    if num == 0 or num == 2:
        return render_template('paper.html', data_list=anslist, telist=teacherdata)
    else:
        return render_template('paper.html', data_list=anslist, form_data=request.form, telist=teacherdata)


def updateproject(num):
    teacherlist = usesql('select * from teacher')
    teacherdata = {}
    for item in teacherlist:
        teacherdata[item[0]] = item[1]
    prolist = usesql('select * from Project')
    prodata = {}
    for item in prolist:
        prodata[item[0]] = item[1]
    anslist = []
    havelist = usesql('select * from HaveProject')
    for item in havelist:
        if num == 2 and item[1] != request.form.get('proid').replace("\'", "\\'"):
            continue
        anslist.append({
            'teid': item[0],
            'teacher': teacherdata[item[0]],
            'proid': item[1],
            'proname': prodata[item[1]],
            'rank': item[2],
            'cost': item[3]
        })
    if num == 0 or num == 2:
        return render_template('project.html', data_list=anslist, telist=teacherdata)
    else:
        return render_template('project.html', data_list=anslist, form_data=request.form, telist=teacherdata)


def updatecourse(num):
    teacherlist = usesql('select * from teacher')
    teacherdata = {}
    for item in teacherlist:
        teacherdata[item[0]] = item[1]
    courselist = usesql('select * from Course')
    coursedata = {}
    for item in courselist:
        coursedata[item[0]] = (item[1], item[2])
    anslist = []
    teachlist = usesql('select * from TeachCourse')
    for item in teachlist:
        if num == 2 and item[1] != request.form.get('courseID').replace("\'", "\\'"):
            continue
        anslist.append({
            'teid': item[0],
            'teacher': teacherdata[item[0]],
            'courseID': item[1],
            'courseName': coursedata[item[1]][0],
            'teachyear': item[2],
            'teachterm': (lambda x:  {1: '春季学期', 2: '夏季学期', 3: '冬季学期'}[x])(item[3]),
            'teachtime': item[4]
        })
    if num == 0 or num == 2:
        return render_template('course.html', data_list=anslist, telist=teacherdata, colist=coursedata)
    else:
        return render_template('course.html', data_list=anslist, form_data=request.form, telist=teacherdata, colist=coursedata)


def updatesearch(num, ansstr, outstr):
    teacherlist = usesql('select * from teacher')
    teacherdata = {}
    for item in teacherlist:
        teacherdata[item[0]] = item[1]
    print(ansstr)
    if num == 0:
        return render_template('search.html', telist=teacherdata, ansstr=ansstr, outstr=outstr)
    else:
        return render_template('search.html', form_data=request.form, telist=teacherdata)


@app.route("/login/", methods=['GET', 'POST'])
def login():
    if session.get('account'):
        return redirect("/")
    if request.method == 'GET':
        return render_template('login.html')
    acceptid = request.form.get('account').replace("\'", "\\'")
    acceptpwd = request.form.get('pwd').replace("\'", "\\'")
    print(acceptid, acceptpwd)
    if acceptid == 'lyh_0921@mail.ustc.edu.cn' and acceptpwd == '123456':
        session['account'] = acceptid
        session.permanent = True
        app.config['PERMANENT_SESSION_LIFETIME'] = timedelta(hours=1)
        return redirect("/")
    else:
        flash('用户名或密码错误!')
        return render_template('login.html')


@app.route("/", methods=['GET', 'POST'])
def index():
    if request.method == 'GET':
        user_info = session.get('account')
        print(user_info)
        if not user_info:
            return redirect("/login/")
        else:
            return render_template("base.html")
    if not request.form:
        session.pop('account')
        print('log out')
        return redirect("/login/")


@app.route("/paper/", methods=['GET', 'POST'])
def paper():
    if request.method == 'GET':
        user_info = session.get('account')
        print(user_info)
        if not user_info:
            return redirect("/login/")
        else:
            return updatepost(0)
    if not request.form:
        session.pop('account')
        print('log out')
        return redirect("/login/")
    try:
        print(request.form)
        papid = int(calint(request.form.get('papid')))
        papname = request.form.get('papname').replace("\'", "\\'")
        papsource = request.form.get('papsource').replace("\'", "\\'")
        papyear = str(request.form.get('papyear'))+'-0-0'
        paptype = int(calint(request.form.get('paptype')))
        paplevel = int(calint(request.form.get('paplevel')))
        inputnum = int(calint(request.form.get("num")))
        teid = []
        rank = []
        isau = []
        for i in range(inputnum):
            teid.append(request.form.get('teid'+str(i)))
            rank.append(int(calint(request.form.get('terank'+str(i)))))
            isau.append(True if request.form.get(
                'isau'+str(i)) == '是' else False)
        action = int(calint(request.form.get('action')))
    except:
        flash('输入错误!')
        return updatepost(1)
    if action == 1:
        if usesql(f"select * from Paper where PaperID = {papid}"):
            flash('论文已存在')
        elif len(set(teid)) != len(teid):
            flash('作者不能重复')
        elif isau.count(True) != 1:
            flash('通讯作者分配错误')
        elif len(set(rank)) != len(rank) or set(rank) != set(range(1, len(rank)+1)):
            flash('作者排名有误')
        else:
            usesql(
                f"insert into Paper value({papid},\'{papname}\',\'{papsource}\',\'{papyear}\',{paptype},{paplevel})")
            for i in range(inputnum):
                usesql(
                    f"insert into PostPaper value(\'{teid[i]}\',{papid},{rank[i]},{isau[i]})")
            flash('添加成功！')
            return updatepost(0)
    elif action == 2:
        if not usesql(f"select * from Paper where PaperID = {papid}"):
            flash('论文不存在')
        else:
            usesql(f"delete from PostPaper where PaperID = {papid}")
            usesql(f"delete from Paper where PaperID = {papid}")
            flash("删除成功！")
            return updatepost(0)
    elif action == 3:
        if not usesql(f"select * from Paper where PaperID = {papid}"):
            flash('论文不存在')
        else:
            usesql(
                f"update Paper set PaperName=\'{papname}\',PaperFrom=\'{papsource}\',PaperYear=\'{papyear}\',PaperType={paptype},PaperLevel={paplevel} where PaperID={papid}")
            flash("成功修改论文,修改其他则先删除数据再重新添加")
            return updatepost(0)
    elif action == 4:
        if not usesql(f"select * from Paper where PaperID = {papid}"):
            flash('论文不存在')
        return updatepost(2)
    return updatepost(1)


@app.route("/project/", methods=['GET', 'POST'])
def project():
    if request.method == 'GET':
        user_info = session.get('account')
        print(user_info)
        if not user_info:
            return redirect("/login/")
        else:
            return updateproject(0)
    if not request.form:
        session.pop('account')
        print('log out')
        return redirect("/login/")
    try:
        print(request.form)
        for i in request.form:
            if request.form.get(i).replace("\'", "\\'") == '':
                flash('输入不能为空')
                return updateproject(1)
        proid = request.form.get('proid').replace("\'", "\\'")
        proname = request.form.get('proname').replace("\'", "\\'")
        profrom = request.form.get('profrom').replace("\'", "\\'")
        procost = float(request.form.get('procost'))
        beginyear = int(calint(request.form.get('beginyear')))
        endyear = int(calint(request.form.get('endyear')))
        protype = int(calint(request.form.get('protype')))
        num = int(calint(request.form.get('total')))
        action = int(calint(request.form.get('action')))
        teid = []
        terank = []
        tecost = []
        for i in range(num):
            teid.append(request.form.get('teid'+str(i)))
            terank.append(int(calint(request.form.get('terank'+str(i)))))
            tecost.append(float(request.form.get('tecost'+str(i))))
    except:
        flash('输入错误')
        return updateproject(1)
    if action == 1:
        if procost != sum(tecost):
            flash('经费统计出现错误！')
        elif len(terank) != len(set(terank)):
            flash('排名出现重复！')
        else:
            if usesql(f"select * from Project where ProjectID = \'{proid}\'"):
                flash(f"项目编号已经存在")
                return updateproject(1)
            usesql(
                f"insert into Project value(\'{proid}\',\'{proname}\',\'{profrom}\',{protype},{procost},{beginyear},{endyear})")
            for i in range(num):
                if not usesql(f"select TeacherName from teacher where TeacherNum = \'{teid[i]}\'"):
                    flash(f"编号为{teid[i]}的教师不存在")
                    return updateproject(1)
            for i in range(num):
                usesql(
                    f"insert into HaveProject value(\'{teid[i]}\',\'{proid}\',{terank[i]},{tecost[i]})")
            return updateproject(0)
    elif action == 2:
        if not usesql(f"select * from Project where ProjectID = \'{proid}\'"):
            flash('项目不存在')
        else:
            usesql(f"delete from HaveProject where ProjectID = \'{proid}\'")
            usesql(f"delete from Project where ProjectID = \'{proid}\'")
            flash("删除成功！")
            return updateproject(0)
    elif action == 3:
        if not usesql(f"select * from Project where ProjectID = \'{proid}\'"):
            flash('项目不存在')
        elif not usesql(f"select * from Project where ProjectID = \'{proid}\' and ProjectCost = {procost}"):
            flash('不能修改项目总经费')
        else:
            usesql(
                f"update Project set ProjectName=\'{proname}\',ProjectFrom=\'{profrom}\',ProjectType={protype},ProjectCost={procost},ProjectBegin = {beginyear},ProjectEnd = {endyear} where ProjectID=\'{proid}\'")
            flash("成功修改项目,修改则先删除数据再重新添加")
            return updateproject(0)
    elif action == 4:
        if not usesql(f"select * from Project where ProjectID = \'{proid}\'"):
            flash('项目不存在')
        else:
            return updateproject(2)
    return updateproject(1)


@app.route("/course/", methods=['GET', 'POST'])
def course():
    if request.method == 'GET':
        user_info = session.get('account')
        print(user_info)
        if not user_info:
            return redirect("/login/")
        else:
            return updatecourse(0)
    if not request.form:
        session.pop('account')
        print('log out')
        return redirect("/login/")
    try:
        print(request.form)
        for i in request.form:
            if request.form.get(i).replace("\'", "\\'") == '':
                flash('输入不能为空')
                return updatecourse(1)
        courseID = request.form.get("courseID").replace("\'", "\\'")
        teachyear = int(calint(request.form.get("teachyear")))
        teachterm = int(calint(request.form.get("teachterm")))
        inputnum = int(calint(request.form.get("num")))
        action = int(calint(request.form.get("action")))
        teid = []
        tetime = []
        for i in range(inputnum):
            teid.append(request.form.get('teid'+str(i)))
            tetime.append(int(calint(request.form.get('tetime'+str(i)))))
    except:
        flash('输入错误')
        return updatecourse(1)
    if action == 1:
        ret = usesql(f"select * from Course where CourseID = \'{courseID}\'")
        if not ret:
            flash("课程不存在！")
            return updatecourse(1)
        else:
            total = int(calint(ret[0][2]))
            if usesql(f"select * from TeachCourse where CourseID = \'{courseID}\' and TeachYear = {teachyear} and TeachTerm = {teachterm}"):
                flash("课程已安排!")
                return updatecourse(1)
            elif total != sum(tetime):
                flash("学时分配错误！")
                return updatecourse(1)
            else:
                for i in range(inputnum):
                    usesql(
                        f"insert into TeachCourse value(\'{teid[i]}\',\'{courseID}\',{teachyear},{teachterm},{tetime[i]})")
                return updatecourse(0)
    elif action == 2:
        if not usesql(f"select * from TeachCourse where CourseID = \'{courseID}\' and TeachYear = {teachyear} and TeachTerm = {teachterm}"):
            flash("该时间段课程尚未安排,无需删除!")
            return updatecourse(1)
        usesql(
            f"delete from TeachCourse where CourseID = \'{courseID}\' and TeachYear = {teachyear} and TeachTerm = {teachterm}")
        flash('成功删除')
        return updatecourse(0)
    elif action == 3:
        flash("修改请先删除再添加")
        return updatecourse(1)
    elif action == 4:
        return updatecourse(2)
    return updatecourse(1)


@app.route("/search/", methods=['GET', 'POST'])
def search():
    if request.method == 'GET':
        user_info = session.get('account')
        print(user_info)
        if not user_info:
            return redirect("/login/")
        else:
            return updatesearch(0, '### 请在上方输入查询需求', 'none')
    if not request.form:
        session.pop('account')
        print('log out')
        return redirect("/login/")
    try:
        print(request.form)
        teid = request.form.get("teid").replace("\'", "\\'")
        beginyear = int(calint(request.form.get("beginyear")))
        endyear = int(calint(request.form.get("endyear")))
    except:
        flash("输入错误!")
        return updatesearch(1, '', 'none')
    ansstr = "## 教师教学科研工作统计"
    ansstr += "(" + str(beginyear) + "~" + str(endyear) + r")\n"
    ansstr += r"#### 教师基本信息\n"
    teinfo = usesql(f"select * from teacher where TeacherNum = \'{teid}\'")
    tename = teinfo[0][1]
    tesex = '男' if teinfo[0][2] == 1 else '女'
    tejob = (lambda x: {
        1: "博士后",
        2: "助教",
        3: "讲师",
        4: "副教授",
        5: "特任教授",
        6: "教授",
        7: "助理研究员",
        8: "特任副研究员",
        9: "副研究员",
        10: "特任研究员",
        11: "研究员"
    }[x])(teinfo[0][3])
    ansstr += f"工号:{teid}⠀⠀⠀⠀⠀⠀⠀⠀姓名:{tename}⠀⠀⠀⠀⠀⠀⠀⠀性别:{tesex}⠀⠀⠀⠀⠀⠀⠀⠀职称:{tejob}"+r"\n"
    outstr = tename+str(beginyear)+"-"+str(endyear)
    ansstr += r"#### 教学情况\n"
    couinfo = usesql(
        f"select Course.CourseID,Course.CourseName,TeachCourse.TeachTime,TeachCourse.TeachYear,TeachCourse.TeachTerm from TeachCourse,Course where TeachCourse.CourseID = Course.CourseID and TeachCourse.TeacherNum = \'{teid}\'")
    print(couinfo)
    for item in couinfo:
        coid = item[0]
        coname = item[1]
        tetime = item[2]
        teyear = item[3]
        teterm = (lambda x: {1: '春', 2: '夏', 3: '秋'}[x])(item[4])
        if teyear <= endyear and teyear >= beginyear:
            ansstr += f"课程号:{coid}⠀⠀⠀⠀⠀⠀⠀⠀课程名:{coname}⠀⠀⠀⠀⠀⠀⠀⠀主讲学时:{tetime}⠀⠀⠀⠀⠀⠀⠀⠀学期:{teyear} {teterm}"+r"\n\n"
    ansstr += r"#### 发表论文情况\n"
    paperinfo = usesql(
        f"select Paper.PaperName,Paper.PaperFrom,SUBSTRING_INDEX(Paper.PaperYear, '-', 1),Paper.PaperType,PostPaper.PostRank,PostPaper.IsAuthor from Paper,PostPaper where Paper.PaperID = PostPaper.PaperID and PostPaper.TeacherNum = \'{teid}\'")
    print(paperinfo)
    ii = 0
    for item in paperinfo:
        papname = item[0]
        papfrom = item[1]
        papyear = item[2]
        paplevel = (lambda x: {
            1: 'CCF-A',
            2: 'CCF-B',
            3: 'CCF-C',
            4: '中文 CCF-A',
            5: '中文 CCF-B',
            6: '无级别'
        }[x])(item[3])
        paprank = item[4]
        papis = '通讯作者' if item[4] == True else ''
        ii += 1
        if int(papyear) <= endyear and int(papyear) >= beginyear:
            ansstr += str(ii) + \
                f". {papname}, {papfrom}, {papyear}, {paplevel},⠀排名:{paprank}, {papis}"+r"\n"
    ansstr += r"#### 承担项目情况\n"
    proinfo = usesql(
        f"select Project.ProjectName,Project.ProjectFrom,Project.ProjectType,Project.ProjectBegin,Project.ProjectEnd,Project.ProjectCost,HaveProject.HaveCost from Project,HaveProject where Project.ProjectID = HaveProject.ProjectID and HaveProject.TeacherNum =  \'{teid}\'")
    ii = 0
    print(proinfo)
    for item in proinfo:
        ii += 1
        proname = item[0]
        profrom = item[1]
        protype = (lambda x: {
            1: '国家级项目',
            2: '省部级项目',
            3: '市厅级项目',
            4: '企业合作项目',
            5: '其它类型项目'
        }[x])(item[2])
        probegin = item[3]
        proend = item[4]
        totalcost = item[5]
        percost = item[6]
        if probegin < endyear and proend > beginyear:
            ansstr += str(ii) + \
                f". {proname}, {profrom}, {protype}, {probegin}-{proend}, 总经费:{totalcost}, 承担经费:{percost}"+r"\n"
    return updatesearch(0, ansstr, outstr)


@app.route("/tmp/", methods=['GET', 'POST'])
def tmp():
    return render_template("tmp.html")


if __name__ == "__main__":
    app.run(debug=True)
