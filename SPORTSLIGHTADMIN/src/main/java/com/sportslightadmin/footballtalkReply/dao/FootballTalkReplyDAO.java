package com.sportslightadmin.footballtalkReply.dao;

import java.util.List;

import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

import com.sportslightadmin.footballtalkReply.dto.FootballTalkReplyDTO;
import com.sportslightadmin.footballtalkReply.dto.FootballTalkReplyPageDTO;

@Mapper
@Repository
public interface FootballTalkReplyDAO {
	public int count(int replyNum); // 페이징 처리를 위한 카운트면 변수명을 talkReplyNum이 아니라 그냥 num으로 해도 되지 않을까
	public List<FootballTalkReplyDTO> footballTalkReplyList(FootballTalkReplyPageDTO pv);
	public void delete(int num);

}
